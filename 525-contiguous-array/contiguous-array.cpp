class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int prefixSum = 0, ans = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i] == 0 ? -1 : 1;

            if(mp.count(prefixSum))
                ans = max(ans, i - mp[prefixSum]);
            else{
                if(!mp.count(prefixSum))
                    mp[prefixSum] = i;
            }
        }
        return ans;
    }
};