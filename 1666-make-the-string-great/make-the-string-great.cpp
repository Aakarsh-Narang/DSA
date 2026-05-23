class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && i<n && abs(s[i] - st.top()) == 32){
                st.pop();
                i++;
            }
            if(i<n)
                st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};