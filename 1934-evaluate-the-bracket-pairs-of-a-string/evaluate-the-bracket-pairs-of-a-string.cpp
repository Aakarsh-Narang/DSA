class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int idx = 0, n = s.size();
        unordered_map<string, string> mp;

        for(auto& v : knowledge){
            mp[v[0]] = v[1];
        }

        while(idx < n){
            // Build Normal Text
            while(idx < n && s[idx] != '('){
                ans += s[idx++];
            }
            idx++;  // Avoid '('

            // Build Key
            string key = "";
            while(idx < n && s[idx] != ')'){
                key += s[idx++];
            }

            if(mp.count(key)){
                ans += mp[key];
            }
            else {
                if(idx < n)
                    ans += "?";
            }
            idx++;  // Avoid ')'
        }

        return ans;
    }
};