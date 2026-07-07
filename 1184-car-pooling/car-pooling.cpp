class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>&b){
            if(a[1] == b[1]) return a[2] > b[2];
            return a[1] < b[1];
        });

        int curr = 0, n = trips.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                curr -= pq.top().second;
                pq.pop();
            }

            curr += trips[i][0];
            if(curr > capacity) return false;
            pq.push({trips[i][2], trips[i][0]});
        }

        return true;
    }
};