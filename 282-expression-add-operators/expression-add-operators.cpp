class Solution {
public:
    void solve(string& s, int& target, int idx, string exp, long long currVal, long long prevOp, vector<string>& ans){
        if(idx == s.size()){
            if(currVal == target)
                ans.push_back(exp);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            string currExp = s.substr(idx, i - idx + 1);
            long long currOp = stoll(currExp);

            // Prevent Leading 0s, eg: 012, 05, etc.
            if(i != idx && s[idx] == '0') break;

            if(idx == 0){
                solve(s, target, i+1, currExp, currOp, currOp, ans);
            }
            else{
                // +
                solve(s, target, i+1, exp + "+" + currExp, currVal + currOp, currOp, ans);
                // -
                solve(s, target, i+1, exp + "-" + currExp, currVal - currOp, -currOp, ans);
                // *
                solve(s, target, i+1, exp + "*" + currExp, currVal - prevOp + (prevOp * currOp), prevOp * currOp, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0,"", 0, 0, ans);
        return ans;
    }
};