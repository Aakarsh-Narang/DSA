class Solution {
public:
    string encode(string& s){
        vector<int> freq(26, 0);
        for(auto& ch: s){
            freq[ch - 'a']++;
        }

        string encoded = "";
        for(int i = 0; i < 26; i++){
            encoded += ((char)('a' + i)) + to_string(freq[i]);
        }

        return encoded;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto& s : strs){
            mp[encode(s)].push_back(s);
        }   

        for(auto& [key, vec] : mp){
            ans.push_back(vec);
        }

        return ans;
    }
};