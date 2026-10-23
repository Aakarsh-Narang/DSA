class Solution {
public:
    bool canSplit(vector<int>& nums, int target, int k){
        int parts = 1, currSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(currSum > target){
                parts++;
                currSum = nums[i];
            }
            if(parts > k) return false;
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while(lo < hi){
            int mid = (hi - lo) / 2 + lo;
            if(canSplit(nums, mid, k)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        return lo;
    }
};