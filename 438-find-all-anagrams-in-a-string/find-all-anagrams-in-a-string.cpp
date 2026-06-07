class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sz = s.size(), l = p.size(), misMatch = 0;

        if(l > sz) return {};
        vector<int> target(26,0), match(26,0), starts;

        for(int i = 0; i < l; i++){
            target[p[i] - 'a']++;
            match[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(target[i] != match[i]) misMatch++;
        }

        if(misMatch == 0) starts.push_back(0);

        for(int i = l; i < sz; i++){
            int out = s[i-l] - 'a';
            int in  = s[i] - 'a';

            // Remove outgoing character
            if(match[out] == target[out]) misMatch++;
            match[out]--;
            if(match[out] == target[out]) misMatch--;

            // Add incoming character
            if(match[in] == target[in]) misMatch++;
            match[in]++;
            if(match[in] == target[in]) misMatch--;

            if(misMatch == 0) starts.push_back(i-l+1);
        }

        return starts;
    }
};