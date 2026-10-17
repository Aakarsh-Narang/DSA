class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10, UniqDigits = 9, curr = 9;
        for(int i = 2; i <= n; i++){
            curr *= UniqDigits;
            ans += curr;
            UniqDigits--;
        }

        return ans;
    }
};