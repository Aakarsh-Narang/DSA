class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; i++)
            diff[i]=(target[i] - nums[i]);

        long long ans = abs(diff[0]);

       for(int i = 1; i < n; i++){
            if(diff[i] > 0){
                if(diff[i] > diff[i-1]) // Need to build Up
                    ans += diff[i] - max(0, diff[i-1]);
            }
            else if(diff[i] < 0){
                if(diff[i-1] > diff[i])  // Need to build Down
                    ans += min(0, diff[i-1]) - diff[i];
            }
        }

        return ans;
    }
};