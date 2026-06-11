class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> temp1, temp2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(temp1.size() == 0 || temp1.back() != nums1[i])
                    temp1.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                if(temp2.size() == 0 || temp2.back() != nums2[j])
                    temp2.push_back(nums2[j]);
                j++;
            }
            else{
                int curr = nums1[i];
                while(i < n && nums1[i] == curr) i++;
                while(j < m && nums2[j] == curr) j++;
            }
        }
        
        while(i < n){ 
            if(temp1.size() == 0 || temp1.back() != nums1[i]) 
                temp1.push_back(nums1[i]);
            i++;
        }

        while(j < m){
            if(temp2.size() == 0 || temp2.back() != nums2[j])
                temp2.push_back(nums2[j]);
            j++;
        }
        return {temp1, temp2};
    }
};