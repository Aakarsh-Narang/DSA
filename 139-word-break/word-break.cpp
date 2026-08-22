class Solution {
public:
    bool Helper(string& s, unordered_set<string>& st, int start, int indx, vector<int>& dp) {
        if(start == s.size())
            return true;

        if(indx == s.size())
            return dp[start] = false;

        if(dp[start] != -1) return dp[start];

        bool include = 0, skip = 0;
        if(st.count(s.substr(start, indx-start+1)))
            include = Helper(s, st, indx+1, indx+1, dp);
        
        skip = Helper(s, st, start, indx+1, dp);

        return dp[start] = skip || include;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);  // dp[i] = -1 → not computed yet
        return Helper(s, st, 0, 0, dp);
    }
};
