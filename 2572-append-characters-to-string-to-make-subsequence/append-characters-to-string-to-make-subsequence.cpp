class Solution {
public:
    int appendCharacters(string s, string t) {
        int s1 = s.size(), s2 = t.size(),i = 0, j = 0;
        while(i<s1 && j<s2){
            if(s[i] == t[j]){
                i++; 
                j++;
            }
            else i++;
        }
        return s2-j;
    }
};