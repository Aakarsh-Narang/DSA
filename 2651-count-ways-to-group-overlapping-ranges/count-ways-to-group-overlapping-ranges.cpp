class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>> ans;
        sort(ranges.begin(), ranges.end());
        int n = ranges.size();

        for(int i = 0; i < n; i++){
            int start = ranges[i][0];
            int end = ranges[i][1];

            while(i+1 < n && end >= ranges[i+1][0]){
                end = max(end, ranges[i+1][1]);
                i++;
            }

            ans.push_back({start, end});
        }
        int sz = ans.size();
        long long ways = 1;

        for(int i = 0; i < sz; i++){
            ways = (ways * 2) % MOD;
        }

        return ways;
    }
};