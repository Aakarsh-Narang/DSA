class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // As per the constraints : 0 <= fromi < toi <= 1000
        map<int, int> times;
        int currSum = 0;

        for(auto& v : trips){
            int people = v[0], from = v[1], to = v[2];
            times[from] += people;
            times[to] -= people;
        }

        for(auto [_, people] : times){
            currSum += people;
            if(currSum > capacity)
                return false;
        }

        return true;
    }
};