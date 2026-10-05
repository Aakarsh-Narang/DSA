class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        unordered_set<string> st;
        for(auto& word : dictionary)
            st.insert(word);

        for(int i = 1; i <= n; i++){
            int skip = dp[i-1] + 1;
            int take = INT_MAX;

            for(int j = 0; j < i; j++){
                if(st.count(s.substr(j, i - j))){
                    take = min(take, dp[j]);
                }
            }

            dp[i] = min(skip, take);
        }

        return dp[n];
    }
};