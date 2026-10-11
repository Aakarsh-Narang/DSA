class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();

        for(int i = 0; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];

            while(i+1 < n && end >= intervals[i+1][0]){
                end = max(end, intervals[i+1][1]);
                i++;
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};