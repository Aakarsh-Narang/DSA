class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size(), lo = 1, hi = n-2;

        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[nums.size() - 1] != nums[nums.size() - 2]) return nums[nums.size() - 1];

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if((mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return -1;
    }
};