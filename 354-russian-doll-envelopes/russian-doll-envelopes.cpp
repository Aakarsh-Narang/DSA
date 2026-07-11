class Solution {
public:
    int correctIdx(vector<int>& lis, int target){
        int lo = 0, hi = lis.size()-1;
        while(lo < hi){
            int mid = (hi - lo) / 2 + lo;
            if(lis[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return hi;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = envelopes.size();

        // Apply LIS on 2nd elements (width will only increase)
        vector<int> lis;
        lis.push_back(envelopes[0][1]);

        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > lis.back()) lis.push_back(envelopes[i][1]);
            else lis[correctIdx(lis, envelopes[i][1])] = envelopes[i][1];
        }

        return lis.size();
    }
};