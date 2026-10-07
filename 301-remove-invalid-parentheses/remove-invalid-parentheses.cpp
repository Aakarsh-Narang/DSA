class Solution {
public:
    bool isValid(string& s){
        stack<char> st;

        for(auto& ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                if(st.empty()) return false;
                else st.pop();
            }
        }
        return st.empty();
    }

    void solve(string& s, unordered_set<string>& st, string curr, int indx, int toUse, int bal){
        int n = s.size();
        // Early Pruning
        if(bal < 0 || toUse < 0) return;

        if(indx == n){
            if(toUse == 0 && isValid(curr)){
                st.insert(curr);
            }
            return;
        }

        if(s[indx] == '('){
            solve(s, st, curr + s[indx], indx+1, toUse-1, bal+1);
            solve(s, st, curr, indx+1, toUse, bal);
        }
        else if(s[indx] == ')'){
            solve(s, st, curr + s[indx], indx+1, toUse-1, bal-1);
            solve(s, st, curr, indx+1, toUse, bal);
        }
        else{
            solve(s, st, curr+s[indx], indx+1, toUse-1, bal);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int tbd = 0, n = s.size();
        unordered_set<string> st;
        vector<string> ans;
        stack<char> stck;

        for(auto& ch : s){
            if(ch == '('){
                stck.push(ch);
            }
            else if(ch == ')'){
                if(stck.empty()) tbd++;
                else stck.pop();
            }
        }
        tbd += stck.size();
        int toUse = n - tbd;

        solve(s, st, "", 0, toUse, 0);

        ans.assign(st.begin(), st.end());
        if(ans.size() == 0) ans.push_back("");

        return ans;
    }
};