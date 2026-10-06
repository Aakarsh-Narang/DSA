class Solution {
public:
    bool compare(string& s1, string& s2, unordered_map<char, int> mp){
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            char ch1 = s1[i++], ch2 = s2[j++];
            if(mp[ch1] < mp[ch2]) return true;
            else if(mp[ch1] > mp[ch2]) return false;
        }
        if(i != s1.size()) return false;

        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for(int i = 0; i < order.size(); i++) mp[order[i]] = i;

        for(int i = 1; i < words.size(); i++){
            if(!compare(words[i-1], words[i], mp)) return false;
        }

        return true;
    }
};