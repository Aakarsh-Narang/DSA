class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] > target) {
                // Normally search left
                if (nums[lo] <= nums[mid]) {
                    if (target >= nums[lo])
                        hi = mid - 1;
                    else
                        lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                // Normally search right
                if (nums[mid] <= nums[hi]) {
                    if (target <= nums[hi])
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        return -1;
    }
};