class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), lo = 0, hi = n - k;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Compare the two elements that would be
            // excluded if we choose window [mid, mid+k-1]
            if (x - arr[mid] > arr[mid + k] - x) {
                // Right side is better -> move window right
                lo = mid + 1;
            } 
            else {
                // Left side is better (or equal)
                // Equal => prefer smaller values
                hi = mid;
            }
        }

        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};