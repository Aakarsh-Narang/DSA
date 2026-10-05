class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n, 0);

        unordered_set<string> st;
        for(auto& word : dictionary)
            st.insert(word);

        for(int i = 0; i < n; i++){
            int skip = i == 0 ? 1 : dp[i-1] + 1;
            int take = INT_MAX;

            for(int j = 0; j <= i; j++){
                if(st.count(s.substr(j, i - j + 1))){
                    take = min(take, (j == 0 ? 0 : dp[j-1]));
                }
            }

            dp[i] = min(skip, take);
        }

        return dp[n-1];
    }
};