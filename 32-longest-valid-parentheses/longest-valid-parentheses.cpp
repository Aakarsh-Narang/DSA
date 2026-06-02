class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        stack<int> st;
        vector<int> dp(n, 0);

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(') st.push(i);
            else{
                if(!st.empty()){
                    int lastIdx = st.top();
                    st.pop();
                    dp[i] = (i-lastIdx+1);  
                    if(lastIdx > 0) dp[i] += dp[lastIdx-1];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};