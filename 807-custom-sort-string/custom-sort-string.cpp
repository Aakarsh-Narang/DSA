class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < order.size(); i++){
            if(freq[order[i] - 'a']){
                string temp(freq[order[i] - 'a'], order[i]);
                ans += temp;
                freq[order[i] - 'a'] = 0;
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a']){
                ans += s[i];
            }
        }

        return ans;
    }
};