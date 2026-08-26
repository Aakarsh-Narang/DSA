class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& dp, int indx){
        if(indx >= nums.size()-1) return true;
        if(dp[indx] != -1) return dp[indx];

        bool canReach = false;
        int range = min(((int)nums.size()-1), (indx + nums[indx]));
        for(int i = indx+1; i <= range; i++){
            canReach = canReach || solve(nums, dp, i);
        }

        return dp[indx] = canReach;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return solve(nums, dp, 0);
    }
};