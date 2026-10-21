class Solution {
public:
    vector<vector<int>> ans;
    void solve(int& n, int& k, vector<int>& curr, int num){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if(num > n) return;

        for(int i = num; i <= n; i++){
            curr.push_back(i);
            solve(n, k, curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(n, k, curr, 1);

        return ans;
    }
};