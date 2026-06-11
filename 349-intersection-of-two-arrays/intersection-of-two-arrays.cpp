class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> ans;
        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);

                while(i+1 < n && nums1[i+1] == ans.back()) i++;
                while(j+1 < m && nums2[j+1] == ans.back()) j++;
            }

            if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }

        return ans;
    }
};