class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long pos = 0, neg = 0, n = nums1.size();

        for(int i = 0; i < n; i++){
            if(k!= 0 && abs(nums1[i] - nums2[i]) % k != 0) return -1;
            if(nums1[i] > nums2[i])
                pos += nums1[i] - nums2[i];
            else
                neg += nums2[i] - nums1[i];
        }
        if(k == 0) return (pos == 0 && neg == 0) ? 0 : -1;
        if(pos != neg) return -1;
        return pos / k;
    }
};