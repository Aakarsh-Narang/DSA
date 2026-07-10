class Solution {
public:
    int correctIdx(vector<int>& lis, int target){
        int ans = 0, lo = 0, hi = lis.size() - 1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(lis[mid] >= target){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > lis.back()) lis.push_back(nums[i]);
            else{
                lis[correctIdx(lis, nums[i])] = nums[i];
            }
        }
        return lis.size();
    }
};