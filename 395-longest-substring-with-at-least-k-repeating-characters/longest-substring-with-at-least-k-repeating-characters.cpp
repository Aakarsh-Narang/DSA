class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), ans = 0;
        // No of unique chars allowed in the window
        for(int maxUnique = 1; maxUnique <= 26; maxUnique++){
            unordered_map<char, int> mp;
            int satisfiedCnt = 0, l = 0, r = 0;
            while(l < n && r < n){
                mp[s[r]]++;
                if(mp[s[r]] == k){
                    satisfiedCnt++;
                }

                while(mp.size() > maxUnique && l <= r){
                    // Check Unique
                    if(mp[s[l]] == k){
                        satisfiedCnt--;
                    }
                    mp[s[l]]--;
                    // Check if last one in Window
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }

                // Ans condition satisfied
                if(satisfiedCnt == mp.size()){
                    ans = max(ans, r - l + 1);
                }
                r++;
            }
        }
        return ans;
    }
};