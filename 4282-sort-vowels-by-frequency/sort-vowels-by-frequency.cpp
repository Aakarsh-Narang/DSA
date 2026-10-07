class Solution {
public:
    string sortVowels(string s) {
        string vowels = "aeiou";
        map<char, int> mp;
        map<char, int> first;

        // Frequency and first occurrence
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(vowels.find(ch) != string::npos) {
                mp[ch]++;

                if(first.find(ch) == first.end())
                    first[ch] = i;
            }
        }

        vector<pair<char, int>> freq;

        for(auto& p : mp)
            freq.push_back(p);

        // Higher frequency first
        // If same frequency, earlier first occurrence first
        sort(freq.begin(), freq.end(),
             [&](pair<char, int>& a, pair<char, int>& b) {
                if(a.second == b.second)
                    return first[a.first] < first[b.first];

                return a.second > b.second;
             });

        // Replace vowels from left to right
        int ptr = 0;

        for(int i = 0; i < s.size(); i++) {
            if(vowels.find(s[i]) != string::npos) {

                s[i] = freq[ptr].first;
                freq[ptr].second--;

                if(freq[ptr].second == 0)
                    ptr++;
            }
        }

        return s;
    }
};