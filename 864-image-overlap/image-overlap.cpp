class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1, ones2;
        int n = img1.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1)
                    ones1.push_back({i, j});

                if(img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        unordered_map<pair<int, int>, int, pair_hash> mp;
        int ans = 0;

        for(int i = 0; i < ones1.size(); i++){
            for(int j = 0; j < ones2.size(); j++){
                int dx = ones1[i].first - ones2[j].first;
                int dy = ones1[i].second - ones2[j].second;

                mp[{dx, dy}]++;
                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
    }
};