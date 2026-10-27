class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        stack<char> st;

        for(auto& ch : s){
            freq[ch - 'a']++;
        }

        for(auto& ch : s){
            int indx = ch - 'a';
            freq[indx]--;
            if(st.empty()){
                st.push(ch);
                used[indx] = 1;
            }
            else{
                if(used[ch-'a']) continue;
                while(!st.empty() && st.top() > ch){
                    char top = st.top();
                    if(freq[top -'a'] == 0) break;
                    st.pop();
                    used[top-'a'] = false;
                }
                st.push(ch);
                used[ch-'a'] = 1;
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};