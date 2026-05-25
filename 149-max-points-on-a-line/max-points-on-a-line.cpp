class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<double, int> mp;
            for(int j = i+1; j < n; j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                // int g = gcd(dx, dy);
                // // Normalizing
                // dx /= g;
                // dy /= g;

                double slope;
                if(dx == 0) slope = 1e8;
                else slope = (1.0 * dy) / dx;
                mp[slope]++;
                ans = max(ans, mp[slope]+1);
            }
        }
        return ans;
    }
};