class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";

        stack<char> st;

        st.push(num[0]);

        for(int i = 1; i < num.size(); i++){
            while(!st.empty() && k && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k--){
            st.pop();
        }
        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        int i = ans.size()-1;
        while(ans.size() && ans[i] == '0'){
            ans.pop_back();
            i--;
        }
        if(ans.size()== 0) ans = "0";
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


// 123456 k = 2
// 1234