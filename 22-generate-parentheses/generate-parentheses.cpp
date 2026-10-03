class Solution {
public: 
    vector<string> ans;
    void solve(int open, int close, string curr, int& n){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(close < open){
            solve(open, close + 1, curr + ')', n);
        }
        if(open < n){
            solve(open + 1, close, curr + '(', n);
        }
    }
    vector<string> generateParenthesis(int n) { 
        solve(0, 0, "", n);

        return ans;
    }
};