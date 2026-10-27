class Solution {
public:
    int lengthOfLastWord(string s) {
        s = " " + s;
        int i = s.size()-1, ans = 0;

        while(s[i] == ' ') i--;

        while(s[i] != ' '){
            ans++;
            i--;
        }

        return ans;
    }
};