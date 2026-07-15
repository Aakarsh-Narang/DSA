class Solution {
public:
    bool judgeSquareSum(int c) {
        long long n = floor(sqrt(c)), l = 0, r = n;

        while(l <= r){
            if(l*l + r*r == c) return true;
            if(l*l + r*r > c) r--;
            if(l*l + r*r < c) l++;
        }
        return false;
    }
};