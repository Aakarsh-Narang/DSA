class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num = 0, n = s.size();
        for(int i = 0; i < n-1; i++){
            if(mp[s[i]] < mp[s[i+1]]){
                num -= mp[s[i]];
            }
            else{
                num += mp[s[i]];
            }
        }

        num += mp[s[n-1]];

        return num;
    }
};