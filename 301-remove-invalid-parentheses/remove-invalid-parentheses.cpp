class Solution {
public:
    void solve(string& s, unordered_set<string>& st, string& curr, int indx, int toUse, int bal){
        int n = s.size();
        // Early Pruning
        if(bal < 0 || toUse < 0) return;

        if(indx == n){
            if(toUse == 0 && bal == 0){
                st.insert(curr);
            }
            return;
        }

        if(s[indx] == '('){
            curr.push_back(s[indx]);
            solve(s, st, curr, indx+1, toUse-1, bal+1);
            curr.pop_back();
            solve(s, st, curr, indx+1, toUse, bal);
        }
        else if(s[indx] == ')'){
            curr.push_back(s[indx]);
            solve(s, st, curr, indx+1, toUse-1, bal-1);
            curr.pop_back();
            solve(s, st, curr, indx+1, toUse, bal);
        }
        else{
            curr.push_back(s[indx]);
            solve(s, st, curr, indx+1, toUse-1, bal);
            curr.pop_back();
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

        string curr;
        solve(s, st, curr, 0, toUse, 0);

        ans.assign(st.begin(), st.end());
        if(ans.size() == 0) ans.push_back("");

        return ans;
    }
};