class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, vector<int>& vis, vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size() ; i++){
            if(vis[i]) continue;
            temp.push_back(nums[i]);
            vis[i] = 1;

            solve(nums, vis, temp);

            vis[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<int> vis(nums.size(), 0);

        solve(nums, vis, temp);

        return ans;
    }
};