class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, string curr, vector<vector<int>>& dp, int i, int j){
        if(i == s1.size() && j == s2.size()){
            return curr == s3;
        }

        if(dp[i][j] != -1) return dp[i][j] == 1 ? true : false;
    
        bool takeFrom1 = false, takeFrom2 = false;
        if(i < s1.size() && s1[i] == s3[i+j])
            takeFrom1 = solve(s1, s2, s3, curr + s1[i], dp, i+1, j);
        if(j < s2.size() && s2[j] == s3[i+j]) 
            takeFrom2 = solve(s1, s2, s3, curr + s2[j], dp, i, j+1); 

        return dp[i][j] = takeFrom1 || takeFrom2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if(n1 + n2 != n3) return false;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2+1, -1));

        return solve(s1, s2, s3, "", dp, 0, 0);
    }
};