class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int ans = 0;
        while(n >= d){
            int shift = 0;
            while(n >= (d<<(shift+1))){
                shift++;
            }
            ans += (1<<shift);
            n -= (d<<shift);
        }

        return ((dividend < 0) ^ (divisor < 0)) ? -ans : ans;
    }
};