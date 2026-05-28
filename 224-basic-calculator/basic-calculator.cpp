class Solution {
public:
    int n, idx = 0;
    long long solve(string& s){
        long long ans = 0;
        int sign = 1;

        while(idx < n){
            // Skip spaces
            while(idx < n && s[idx] == ' ')
                idx++;

            if(idx >= n)  break;

            // Closing bracket ends current recursive scope
            if(s[idx] == ')'){
                idx++;
                return ans;
            }

            // Update sign
            if(s[idx] == '+'){
                sign = 1;
                idx++;
            }

            else if(s[idx] == '-'){
                sign = -1;
                idx++;
            }

            // Bracket expression
            else if(s[idx] == '('){
                idx++;

                int val = solve(s);

                ans += sign * val;
            }

            // Normal number
            else{
                long long num = 0;

                while(idx < n && isdigit(s[idx])){
                    num = num * 10 + (s[idx++] - '0');
                }

                ans += sign * num;
            }
        }

        return ans;
    }
    int calculate(string s) {
        s = "(" + s + ")";
        n = s.size();
        return solve(s);
    }
};