class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;

        while(lo <= hi){
            int mid = (hi - lo)/2 + lo;
            if(nums[mid] == target) return mid;
            // Right half is sorted
            if(nums[mid] <= nums[hi]){
                // Target is in sorted half
                if(nums[mid] <= target && nums[hi] >= target) 
                    lo = mid + 1; 
                else 
                    hi = mid - 1;
            }
            // Left half is sorted
            else{
                // Target is in sorted half
                if(nums[mid] >= target && nums[lo] <= target) 
                    hi = mid - 1;
                else  
                    lo = mid + 1;
            }
        }
        return -1;
    }
};