class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(') st.push(i);
            else{
                // Remove the matching or boundary, if matching exits well and good, else it will serve as new boundary
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};