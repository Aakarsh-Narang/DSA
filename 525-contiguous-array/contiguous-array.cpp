class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int prefixSum = 0, ans = 0;
        prefixSum = (nums[0] == 0) ? -1 : 1;
        mp[prefixSum] = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0) prefixSum--;
            else prefixSum++;

            if(prefixSum == 0) ans = max(ans, i+1);
            else if(mp.count(prefixSum))
                ans = max(ans, i - mp[prefixSum]);
            else{
                if(!mp.count(prefixSum))
                    mp[prefixSum] = i;
            }
        }
        return ans;
    }
};