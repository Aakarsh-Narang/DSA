class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), N = (n1 + n2);
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = n1;  // Cut can be at the end of array as well

        while(lo <= hi){
            int cut1 = (hi - lo) / 2 + lo;
            int cut2 = (N+1) / 2 - cut1;

            // Everything to left of cut1 Element belong to left & from the element belongs to the right
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(l1 <= r2 && l2 <= r1){
                if(N % 2 == 0){
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else{
                    // We have (N+1)/2 elements on the left, therefore we choose from left
                    return max(l1, l2) * 1.0;
                }
            }
            // Too many elments on the left
            else if(l1 > r2){
                hi = cut1 - 1;
            }
            // Too less elements on the right (l2 > r1)
            else{
                lo = cut1 + 1;
            }
        }

        return 0.00;
    }
};