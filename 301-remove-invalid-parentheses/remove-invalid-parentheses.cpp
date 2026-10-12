class Solution {
public:
    void solve(string& s, string& curr, unordered_set<string>& ans, int bal, int toUse, int indx){
        if(indx == s.size()){
            if(bal == 0 && toUse == 0)  
                ans.insert(curr);
            return;
        }

        if(bal < 0 || toUse < 0) return;

        if(s[indx] == '('){
            solve(s, curr, ans, bal, toUse, indx+1);
            curr.push_back(s[indx]);

            solve(s, curr, ans, bal+1, toUse-1, indx+1);

            curr.pop_back();
        }
        else if(s[indx] == ')'){
            solve(s, curr, ans, bal, toUse, indx+1);
            curr.push_back(s[indx]);

            solve(s, curr, ans, bal-1, toUse-1, indx+1);

            curr.pop_back();
        }
        else{
            curr.push_back(s[indx]);

            solve(s, curr, ans, bal, toUse-1, indx+1);

            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        unordered_set<string> ans;
        int toUse = 0, n = s.size(), tbd = 0;

        for(auto& ch : s){
            if(ch == '(') st.push(ch);
            else if(ch == ')'){
                if(st.empty()) tbd++;
                else st.pop();
            }
        }

        tbd += st.size();
        toUse = n - tbd;

        string curr = "";
        solve(s, curr, ans, 0, toUse, 0);

        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};