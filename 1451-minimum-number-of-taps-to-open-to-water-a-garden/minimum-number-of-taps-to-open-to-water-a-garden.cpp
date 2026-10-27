class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;

        for (int i = 0; i <= n; i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            intervals.push_back({left, right});
        }

        sort(intervals.begin(), intervals.end());

        int currEnd = 0, farthest = 0, taps = 0, i = 0;

        while (currEnd < n) {
            farthest = currEnd;

            while (i < intervals.size() && intervals[i].first <= currEnd) {
                farthest = max(farthest, intervals[i].second);
                i++;
            }

            if (farthest == currEnd) return -1;

            taps++;
            currEnd = farthest;
        }

        return taps;
    }
};