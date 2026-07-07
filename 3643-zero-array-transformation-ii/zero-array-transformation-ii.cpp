class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int k){
        int n = nums.size(), currSum = 0;
        vector<int> diff(n+1, 0);

        // Building diff array as per queries
        for(int i = 0; i < k; i++){
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }

        // Updating nums array
        for(int i = 0; i < n; i++){
            currSum += diff[i];
            if(currSum < nums[i]) return false;
        }

        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo = 0, hi = queries.size(), ans = -1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(isPossible(nums, queries, mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};