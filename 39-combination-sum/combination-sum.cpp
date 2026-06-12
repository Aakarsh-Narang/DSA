class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, vector<int>& curr, int idx, int sum, int target){
        if(sum > target || idx >= candidates.size()) return;
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(candidates[idx]);
        solve(candidates, curr, idx, sum+candidates[idx], target);
        curr.pop_back();  // Backtrack

        solve(candidates, curr, idx+1, sum, target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, temp,  0, 0, target);

        return ans;
    }
};