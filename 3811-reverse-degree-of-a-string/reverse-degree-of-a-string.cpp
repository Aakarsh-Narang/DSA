class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            int ch = (26 - (s[i] - 'a'));
            ans += (ch * (i+1));
        }

        return ans;
    }
};