class Solution {
public:
    vector<int> dp;
    int decode(string& s, int i){
        int n = s.size();
        if(i == n){
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0;

        int skip = 0, group = 0;
        if(i < n-1 && ((s[i] == '1') || (s[i] == '2' && s[i+1] <= '6'))){
            group = decode(s, i+2);
        } 
        skip = decode(s, i+1);

        return dp[i] =  skip + group;
    }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        
        dp.resize(n, -1);

        return decode(s, 0);
    }
};