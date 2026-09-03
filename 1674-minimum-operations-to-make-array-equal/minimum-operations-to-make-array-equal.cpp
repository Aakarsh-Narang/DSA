class Solution {
public:
    int minOperations(int n) {
        // median of 1st n odd numbers is n
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            ans += n - (2*i + 1);
        }
        return ans;
    }
};
// 1 3 5 7 9 11
// 5 3 1-1-3 -5

// 1 3 5 7 9
// 4 1 0-1-4