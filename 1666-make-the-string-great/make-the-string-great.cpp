class Solution {
public:
    string makeGood(string s) {
        string ans ="";
        bool flg = 1;
        while(flg){
            flg = 0;
            int n = s.size();
            for(int i = 0; i<n; i++){
                if(i+1 < n && abs(s[i] - s[i+1]) == 32){
                    i++;
                    flg = 1;
                }
                else{
                    ans += s[i];
                }
            }
            s = ans;
            ans = "";
        }
        return s;
    }
};