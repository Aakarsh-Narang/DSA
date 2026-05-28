class Solution {
public:
    int calculate(string s) {
        long long ans = 0, num = 0;
        int sign = 1;
        stack<long long> st;

        for(char& c : s){
            if(c == ')'){
                ans += sign * num;
                num = 0;
                
                int prevSign = st.top();
                st.pop();
                int prevRes = st.top();
                st.pop();

                ans = (prevSign * ans) + prevRes;
            }
            else if(c == '('){
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(c == '+'){
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            else if(c == '-'){
                ans += sign * num;
                num = 0;
                sign = -1;
            }
            else if(isdigit(c)){
                num = num*10 + (c - '0');
            }
        } 
        ans += num * sign;
        return ans;
    }
};