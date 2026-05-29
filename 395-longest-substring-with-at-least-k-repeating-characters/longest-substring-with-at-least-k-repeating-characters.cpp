class Solution {
public:
    int longestSubstring(string s, int k) {
        int uniqueCount, ans = 0, l = 0, r = 0, n = s.size();

        for(int maxUnique = 1; maxUnique <= 26; maxUnique++){
            unordered_map<char, int> mp;
            l = 0, r = 0, uniqueCount = 0;
            while(l < n && r < n){
                mp[s[r]]++;
                if(mp[s[r]] == k){
                    uniqueCount++;
                }

                if(uniqueCount == mp.size())
                    ans = max(ans, r-l+1);

                while(l <= r && mp.size() > maxUnique){
                    if(mp[s[l]] == k) uniqueCount--;
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
                r++;
            }
        }

        return ans;
    }
};