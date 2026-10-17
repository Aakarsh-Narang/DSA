class Solution {
public:
    int count(int n){
        if(n == 0) return 1;
        int ans = 9, uniqDigits = 9;
        for(int i = 1; i < n; i++){
            ans *= uniqDigits;
            uniqDigits--;
        }

        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;

        for(int i = 0; i <= n; i++){
            ans += count(i);
        }
        return ans;
    }
};