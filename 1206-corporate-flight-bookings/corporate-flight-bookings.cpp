class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1, 0);
        
        for(auto& b : bookings){
            int first = b[0], last = b[1], seats = b[2];
            diff[first-1] += seats;
            diff[last] -= seats;
        }

        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += diff[i];
            ans.push_back(cnt);
        }

        return ans;
    }
};