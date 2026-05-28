class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == ']'){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return (st.size() + 1) / 2;
    }
};