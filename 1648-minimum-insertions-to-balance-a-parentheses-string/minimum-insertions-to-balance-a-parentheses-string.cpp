class Solution {
public:
    int minInsertions(string s) {
        int n = s.size(), cnt = 0;
        stack<char> st;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(ch);
            }
            else{
                if(i+1 < n && s[i+1] == ')'){
                    // 1 missing ( : _))
                    if(st.empty()) cnt++;
                    // Valid Case : ())
                    else{ 
                        st.pop();
                    }

                    i++;
                }
                else{
                    // 1 alone ) : _)_
                    if(st.empty()) cnt += 2;
                    // 1 missing ) : ()_
                    else{ 
                        cnt++;
                        st.pop();
                    }
                }
            }
        }

        // For each extra ( -> Add 2 ) brackets
        return cnt + st.size()*2;
    }
};