class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0, r = 0, n = s.size(), ans = 0;

        while(r < n && l < n){
            char ch = s[r++];
            freq[ch]++;
            while(r < n && freq[ch] <= 1){
                ch = s[r++];
                freq[ch]++;
            }

            ans = max(ans, r-l-1);

            char faulty = s[r-1];
            while(l <= r && freq[faulty] > 1){
                ch = s[l++];
                freq[ch]--;
            }
        }
        ans = max(ans, r-l);

        return ans;
    }
};