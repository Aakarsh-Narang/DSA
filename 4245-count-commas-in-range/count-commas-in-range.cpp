class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;

        int cnt = 0, sub = 1000;

        while(n >= 1000){
            cnt += min(1000, n - sub + 1);
            n -= sub;
        }

        return cnt;
    }
};