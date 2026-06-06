class Solution {
public:
    bool isPossible(int n, unsigned long long steps){
        unsigned long long  sum = (steps * (steps+1)) / 2;

        // cout << steps << " steps -> " <<  "sum  " << sum << endl;
        return sum <= n;
    }
    int arrangeCoins(int n) {
        int lo = 0, hi = n, ans = 0;

        while(lo <= hi){
            unsigned long long mid = (hi - lo) / 2 + lo;
            if(isPossible(n, mid)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};