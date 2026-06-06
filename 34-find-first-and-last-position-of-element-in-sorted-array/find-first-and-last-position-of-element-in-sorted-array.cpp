class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int fi = -1, lo = 0, hi = nums.size()-1;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(nums[mid] == target){
                fi = mid;
                hi = mid - 1;
                continue;
            }
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return fi;
    }
    int secondOcc(vector<int>& nums, int target){
        int li = -1, lo = 0, hi = nums.size()-1;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(nums[mid] == target){
                li = mid;
                lo = mid + 1;
                continue;
            }
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return li;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums, target), secondOcc(nums, target)};
    }
};