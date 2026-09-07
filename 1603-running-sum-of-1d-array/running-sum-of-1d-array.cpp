class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size(), curr = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            curr += nums[i];
            ans[i] = curr;
        }

        return ans;
    }
};