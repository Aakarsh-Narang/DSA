class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, long long>> arr;

        for(int i = 0; i < nums.size(); i++){
            arr.push_back({nums[i], cost[i]});
        }
        sort(arr.begin(), arr.end());

        for(int i = 1; i < nums.size(); i++){
            arr[i].second += arr[i-1].second;
        }

        long long sum = arr[nums.size() - 1].second;

        int lo = 0, hi = nums.size()-1, ansIndx = 0;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;

            if(arr[mid].second >= sum/2.0){
                ansIndx = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        long long target = arr[ansIndx].first, totalCost = 0;

        for(int i = 0; i < nums.size(); i++){
            totalCost += abs(nums[i] - target) * cost[i];
        }

        return totalCost;
    }
};