class Solution {
public:
    bool judgeSquareSum(int c) {
        long long n = floor(sqrt(c));

        for(long long i = 0; i <= n; i++){
            double b = sqrt(c - i*i);
            if(b == (int)b) return true;
        }
        return false;
    }
};