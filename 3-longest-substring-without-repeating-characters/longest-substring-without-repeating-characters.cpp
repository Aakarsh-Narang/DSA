class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = 0, r = 0, ans = 0;
        unordered_map<char, int> mp;

        int totalChar = 0, uniqueChar = 0;
        while(r < n){
            mp[s[r]]++;

            if(mp[s[r]] == 1){
                uniqueChar++;
                totalChar++;
            }
            else if(mp[s[r]] == 2){
                uniqueChar--;
            }

            while(l <= r && uniqueChar != totalChar){
                mp[s[l]]--;
                if(mp[s[l]] == 1) uniqueChar++;
                if(mp[s[l]] == 0) totalChar--, uniqueChar--;
                l++;
            }

            if(uniqueChar == totalChar){
                ans = max(ans, r - l + 1);
            }

            r++;
        }

        return ans;
    }
};