class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        vector<int> dp(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(st.empty()) continue;
                int lastIdx = st.top();
                st.pop();
                dp[i] = (i - lastIdx + 1);
                if(lastIdx > 0) dp[i] += dp[lastIdx - 1];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};