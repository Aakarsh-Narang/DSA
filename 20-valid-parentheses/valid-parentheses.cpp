class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(ch == ')'){
                    if(!st.empty() && st.top() == '('){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                if(ch == '}'){
                    if(!st.empty() && st.top() == '{'){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                if(ch == ']'){
                    if(!st.empty() && st.top() == '['){
                        st.pop();
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};