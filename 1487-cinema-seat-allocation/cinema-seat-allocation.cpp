class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        if(reservedSeats.empty()) return 2 * n;

        int ans = 0, sz = reservedSeats.size(), i = 0, last = 1;
        sort(reservedSeats.begin(), reservedSeats.end());

        while(i < sz){
            bool block1 = 1, block2 = 1, block3 = 1;
            do{
                if(2 <= reservedSeats[i][1] && reservedSeats[i][1] <= 5) block1 = 0;
                if(4 <= reservedSeats[i][1] && reservedSeats[i][1] <= 7) block2 = 0;
                if(6 <= reservedSeats[i][1] && reservedSeats[i][1] <= 9) block3 = 0;
                i++;
            } while((i < sz && reservedSeats[i][0] == reservedSeats[i-1][0]));
            i--;
            if(block1 && block3) ans += 2;
            else if(block1 || block2 || block3) ans++;
  
            ans += (reservedSeats[i][0] - last) * 2;
            last = reservedSeats[i][0] + 1;

            i++;
        }
        if(sz > 0)
            ans += (n - reservedSeats[sz - 1][0]) * 2;

        return ans;
    }
};