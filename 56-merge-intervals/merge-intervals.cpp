class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i<n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            while(i+1 < n && end >= intervals[i+1][0]){
                end = max(end, intervals[i+1][1]);
                // start = min(start, intervals[i][0]);
                i++;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};