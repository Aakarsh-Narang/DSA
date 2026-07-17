class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(j >= p.size()) return i == s.size();

        if(dp[i][j] != -1) return dp[i][j];

        bool currMatch = (i < s.size()) && ((s[i] == p[j]) || (p[j] == '.'));
        bool ans;

        if(j+1 < p.size() && p[j+1] == '*'){
            ans = match(s, p, i, j+2, dp) || (currMatch && match(s, p, i+1, j, dp)); // Skip x* or use one x
        }
        else{
            ans = currMatch && match(s, p, i+1, j+1, dp);
        }

        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return match(s, p, 0, 0, dp);
    }
};