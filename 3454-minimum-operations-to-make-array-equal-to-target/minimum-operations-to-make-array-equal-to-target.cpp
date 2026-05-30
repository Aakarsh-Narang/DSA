class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n =nums.size();

        for(int i = 0; i < n; i++){
            target[i] = target[i] - nums[i];
        }

        long long ans = abs(target[0]);
        
        for(int i = 1; i < n; i++){
            if(target[i] < 0){
                if(target[i] < target[i-1]){
                    ans +=  min(target[i-1], 0) - target[i];
                }
            }
            if(target[i] > 0){
                if(target[i] > target[i-1]){
                    ans += target[i] - max(target[i-1], 0);
                }        
            }
        }
        return ans;
    }
};