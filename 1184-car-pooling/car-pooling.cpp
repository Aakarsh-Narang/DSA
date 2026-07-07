class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // As per the constraints : 0 <= fromi < toi <= 1000
        vector<int> times(1001, 0);
        int currSum = 0;

        for(auto& v : trips){
            int people = v[0], from = v[1], to = v[2];
            times[from] += people;
            times[to] -= people;
        }

        for(int i = 0; i < 1001; i++){
            currSum += times[i];
            if(currSum > capacity)
                return false;
        }

        return true;
    }
};