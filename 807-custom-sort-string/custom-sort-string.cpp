class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> st;
        vector<int> freq(26, 0);
        string ans = "";

        for(auto& ch : order){
            st.insert(ch);
        }
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < order.size(); i++){
            if(freq[order[i] - 'a']){
                string temp(freq[order[i] - 'a'], order[i]);
                ans += temp;
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(st.find(s[i]) == st.end()){
                ans += s[i];
            }
        }

        return ans;
    }
};