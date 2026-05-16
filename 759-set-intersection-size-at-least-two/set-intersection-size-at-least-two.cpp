class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> ans;
        int n = intervals.size();
        // Assumption: last1 > last2
        int last1 = intervals[n-1][0]+1, last2 = intervals[n-1][0];
        ans.push_back(last1);
        ans.push_back(last2);
        for(int i = n-2; i >= 0; i--){
            int end = intervals[i][1];
            if(last1 <= end && last2 <= end) continue;
            else if(last1 <= end || last2 <= end){
                last1 = last2;
                last2 = intervals[i][0];
                ans.push_back(last1);
            }
            else{
                last2 = intervals[i][0];
                last1 = intervals[i][0]+1;
                ans.push_back(last1);
                ans.push_back(last2);
            }
        }
        return ans.size();
    }
};