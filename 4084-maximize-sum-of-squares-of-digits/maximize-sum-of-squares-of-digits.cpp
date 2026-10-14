class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9 < sum) return "";
        string ans = "";

        while(num--){
            int curr = 9;
            while(curr > sum) curr--;

            sum -= curr;
            ans += to_string(curr);
        }

        return ans;
    }
};