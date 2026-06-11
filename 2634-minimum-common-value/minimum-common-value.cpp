class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

        if(nums1[n1-1] < nums2[0]  || nums1[0] > nums2[n2-1]) return -1;

        while(i < n1 && j < n2){
            if(nums1[i] ==  nums2[j]){
                return nums1[i];
            }
            if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return -1;
    }
};