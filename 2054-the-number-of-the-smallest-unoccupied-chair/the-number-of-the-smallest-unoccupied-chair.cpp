class Solution {
public:
    using ll = long long;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> occupiedChairs;
        priority_queue<int, vector<int>, greater<int>> availChairs; // Min heaps

        for(int i = 0; i<= 1e4; i++)
            availChairs.push(i);

        vector<tuple<int, int, int>> newTimes;
        for(int i = 0; i<times.size(); i++){
            newTimes.push_back({times[i][0], times[i][1], i});
        }
        sort(newTimes.begin(), newTimes.end());

        for(auto& t:newTimes){
            auto [s, e, frnd] = t;
            while(!occupiedChairs.empty() && occupiedChairs.top().first <= s){
                availChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            if(frnd == targetFriend)  return availChairs.top();

            int chair = availChairs.top();
            availChairs.pop();
            occupiedChairs.push({e, chair});
        }
        return -1;
    }
};