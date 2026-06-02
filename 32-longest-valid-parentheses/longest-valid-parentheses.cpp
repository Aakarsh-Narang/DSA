class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, n = s.size();
        stack<int> st;
        vector<int> dp(n+1, 0);

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(') st.push(i+1);
            else{
                if(st.empty()) dp[i+1] = 0;
                else{
                    int lastIdx = st.top();
                    st.pop();
                    dp[i+1] = dp[lastIdx-1] + (i-lastIdx+2);  
                    // cout << i << " "<<lastIdx-1 << " " <<dp[lastIdx] << " " << dp[lastIdx+1]<<endl;
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};