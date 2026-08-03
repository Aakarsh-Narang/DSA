class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0, s1 = word1.size(), s2 = word2.size();
        string ans = "";

        while(i < s1 || j < s2){
            if(i < s1) ans += word1[i++];
            if(j < s2) ans += word2[j++];
        }
        
        return ans;
    }
};