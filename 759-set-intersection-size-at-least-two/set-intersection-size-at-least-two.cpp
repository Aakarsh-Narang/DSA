class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        // for(auto& v:intervals){
        //     cout<< v[0] << " "<< v[1] << endl;
        // }
        // last2 < last1 (assumption for the algo)
        int n = intervals.size(), last1 = intervals[0][1], last2 = intervals[0][1]-1;
        // We will also build nums vector for a more versatile soln
        vector<int> nums;
        nums.push_back(last2);
        nums.push_back(last1);
        for(int i = 1; i<n; i++){
            // Current interval is already satisfied
            if(last1 >= intervals[i][0] && last2 >= intervals[i][0]) continue;
            if(last1 >= intervals[i][0] || last2 >= intervals[i][0]){
                last2 = last1;
                last1 = intervals[i][1];
                nums.push_back(last1);
            }
            else{
                last1 = intervals[i][1];
                last2 = intervals[i][1]-1;
                nums.push_back(last2);
                nums.push_back(last1);
            }
        }
        // for(auto& n:nums) cout<<n<<" ";
        return nums.size();
    }
};