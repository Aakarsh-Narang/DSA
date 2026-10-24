class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, curr = 0;

        for(int i = 0; i < n; i++){
            curr = max(nums[i], curr + nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};