class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        for(auto& ch : num){
            int n = ch - '0';
            while(!st.empty() && k && st.top() > n){
                st.pop();
                k--;
            }
            if(st.empty() && n == 0) continue;
            st.push(n);
        }
        while(!st.empty() && k--) st.pop();

        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()){
            ans += (st.top() + '0');
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};