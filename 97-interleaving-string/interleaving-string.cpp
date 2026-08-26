class Solution {
public:
    bool isPossible(string& s1, string& s2, string& s3, vector<vector<int>>& dp, int i, int j){
        if(i >= s1.size() && j >= s2.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        bool take1 = false, take2 = false;
        if(i < s1.size() && s1[i] == s3[i+j])
            take1 = isPossible(s1, s2, s3, dp, i+1, j);
        if(j < s2.size() && s2[j] == s3[i+j])
            take2 = isPossible(s1, s2, s3, dp, i, j+1);

        return dp[i][j] = take1 || take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if(n1 + n2 != n3) return false;
        // if(n1 == 0) return s2 == s3;
        // if(n2 == 0) return s1 == s3;

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return isPossible(s1, s2, s3, dp, 0, 0);
    }
};