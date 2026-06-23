class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());

        if(r.back()[0] != n){
            r.push_back({n, n-1});
        }

        int m = r.size();

        // Decide what maximum height can a restricted building actually reach
        for(int i = 1; i < m; i++){
            int dist = r[i][0] - r[i-1][0];
            r[i][1] = min(r[i][1], r[i-1][1] + dist);
        }

        for(int i = m-2; i >= 0; i--){
            int dist = r[i+1][0] - r[i][0];
            r[i][1] = min(r[i][1], r[i+1][1] + dist);
        }

        // Find max heights bw the restricted buildings
        int ans = 0;
        for(int i = 0; i < m-1; i++){
            int dist = r[i+1][0] - r[i][0];
            int best = (r[i][1] + r[i+1][1] + dist) / 2;
            ans = max(ans, best);
        }

        return ans;
    }
};