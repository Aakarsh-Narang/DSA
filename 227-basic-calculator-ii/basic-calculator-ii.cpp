class Solution {
public:
    int calculate(string s) {
        int n = s.size(), ans = 0, idx = 0, prev;

        while(idx < n && s[idx] == ' ') idx++;

        while(idx < n && isdigit(s[idx])) {
            ans = ans * 10 + (s[idx++] -'0');
        }
        prev = ans;

        for(int i = idx; i < n; ){
            int curr = 0;
            
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;

            char op = s[i++];

            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;

            while(i < n && isdigit(s[i])) {
                curr = curr * 10 + (s[i++] -'0');
            }
            if(op == '+'){
                ans = ans + curr;
                prev = curr;
            }
            else if(op == '-'){
                ans = ans - curr;
                prev = -curr;
            }
            else if(op == '*'){
                ans = ans - prev + (prev * curr);
                prev = prev * curr;
            }
            else{
                ans = ans - prev + (prev / curr);
                prev = prev / curr;
            }
        }
        return ans;
    }
};