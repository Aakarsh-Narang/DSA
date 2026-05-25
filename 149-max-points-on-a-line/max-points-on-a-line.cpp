class Solution {
public:
    struct HashPair {
        size_t operator()(const pair<int, int>& p) const{
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<pair<int, int>, int, HashPair> mp;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                pair<int, int> slope = make_pair(dx, dy);
                mp[slope]++;
                ans = max(ans, mp[slope]+1);
            }
        }
        return ans;
    }
};