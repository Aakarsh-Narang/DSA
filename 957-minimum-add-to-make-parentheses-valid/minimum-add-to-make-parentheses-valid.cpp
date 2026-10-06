class Solution {
public:
    int minAddToMakeValid(string s) {
        int extraClosing = 0;
        stack<char> st;

        for(auto& ch : s){
            if(ch == '(') st.push(ch);
            else{
                if(st.empty()) extraClosing++;
                else st.pop();   // Match found
            }
        }
        // st.size() -> Extra Opening Brackets
        return st.size() + extraClosing;
    }
};