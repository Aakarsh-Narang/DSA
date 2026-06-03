class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& vis, int idx){
        if(vis[idx]) return 0;

        //Mark current
        vis[idx] = 1;

        return 1 + dfs(nums, vis, nums[idx]);
    }
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        vector<int> vis(n, 0);  // Keeping track with indices and not values

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            ans = max(ans, dfs(nums, vis, i));
        }
        return ans;
    }
};