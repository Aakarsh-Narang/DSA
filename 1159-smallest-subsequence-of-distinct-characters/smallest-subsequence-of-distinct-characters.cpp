class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        stack<char> st;

        for(auto& ch : s){
            freq[ch-'a']++;
        }

        for(auto& ch : s){
            int indx = ch - 'a';
            freq[indx]--;

            if(st.empty()){
                st.push(ch);
                used[indx] = 1;
            }
            else{
                if(used[indx]) continue;

                while(!st.empty() && st.top() > ch){
                    if(freq[st.top()-'a'] == 0) break; // Last one of the kind
                    used[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(ch);
                used[indx] = 1;
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