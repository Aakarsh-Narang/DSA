class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            // Ignore spaces
            if(s[i] == ' ') continue;

            // Parse complete number
            if(isdigit(s[i])){
                string num = "";

                while(i < n && isdigit(s[i])){
                    num += s[i];
                    i++;
                }
                i--; // compensate extra increment
                st.push(num);
            }

            else if(s[i] == '+' || s[i] == '-'){
                st.push(string(1, s[i]));
            }

            else{
                 // Get next complete number
                string num = "";
                i++;

                while(i < n && s[i] == ' ')
                    i++;

                while(i < n && isdigit(s[i])){
                    num += s[i];
                    i++;
                }
                i--;
                int right = stoi(num);
                int left = stoi(st.top());

                st.pop();
                int val;

                if(s[i - num.size()] == '*'){
                    val = left * right;
                }
                else {
                    val = left / right;
                }
                st.push(to_string(val));
            }
        }

        // Evaluate remaining + and -
        vector<string> expr;

        while(!st.empty()){
            expr.push_back(st.top());
            st.pop();
        }

        reverse(expr.begin(), expr.end());
        int ans = stoi(expr[0]);

        for(int i = 1; i < expr.size(); i += 2){
            string op = expr[i];
            int num = stoi(expr[i + 1]);
            if(op == "+")
                ans += num;
            else
                ans -= num;
        }
        return ans;
    }
};