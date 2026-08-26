class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), currSum = 0, ans = INT_MIN;
        for(int i = 0; i < n; i++){
            currSum = max(currSum + nums[i], nums[i]);
            ans = max(ans, currSum);
        }

        return ans;
    }
};