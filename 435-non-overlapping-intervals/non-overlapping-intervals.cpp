class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int prevEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(prevEnd > intervals[i][0])
                cnt++;
            else
                prevEnd = intervals[i][1];
        }
        return cnt;
    }
};