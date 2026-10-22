class Solution {
public:
    void build(int n, int open, int close, string curr, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            build(n, open+1, close, curr + '(', ans);
        }
        if(close < open){
            build(n, open, close + 1, curr + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        build(n, 0, 0, "", ans);

        return ans;
    }
};