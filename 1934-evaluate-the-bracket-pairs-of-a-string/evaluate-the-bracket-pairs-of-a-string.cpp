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
            int nextOpen = s.find('(', idx);
            if(nextOpen != string::npos)
                ans += s.substr(idx, nextOpen-idx);  // Excluding (

            int nextClose = s.find(')', idx);
            if(nextClose != string::npos){
                string key = s.substr(nextOpen+1, nextClose - nextOpen - 1);  // Excluding )
              
                if(mp.count(key))  ans += mp[key];
                else ans += "?";

                idx = nextClose + 1;  // Move Index in chunks
            }
            else{   
                // No closing brackets left in string, so add entire string and get done with
                ans += s.substr(idx);
                idx = n;
            }
                
        }
        return ans;
    }
};