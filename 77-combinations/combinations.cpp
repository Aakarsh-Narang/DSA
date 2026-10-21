class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, vector<int>& curr, int num){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(num > n) return;

        curr.push_back(num);
        solve(n, k, curr, num+1);
        curr.pop_back();

        solve(n, k, curr, num+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n, k, curr, 1);

        return ans;
    }
};