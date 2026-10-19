class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0, n = s.size();

        for(int maxUnique = 1; maxUnique <= 26; maxUnique++){
            unordered_map<int, int> mp;
            int l= 0, r= 0, satisfied = 0;
            while(r < n){
                mp[s[r]]++;

                if(mp[s[r]] == k) satisfied++;

                while(mp.size() > maxUnique){
                    if(mp[s[l]] == k){
                        satisfied--;
                    }

                    mp[s[l]]--;

                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }

                    l++;
                }
                if(satisfied == mp.size()){
                    ans = max(ans, r-l+1);
                }
                r++;
            }
        }

        return ans;
    }
};