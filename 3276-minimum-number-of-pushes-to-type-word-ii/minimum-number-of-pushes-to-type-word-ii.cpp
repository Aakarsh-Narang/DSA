class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(auto& ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater());

        int clicks = 0;

        for(int i = 0; i < 26; i++){
            int cnt = freq[i];
            if(cnt == 0) break;
            clicks += (i/8 + 1)*freq[i];
        }

        return clicks;
    }
};