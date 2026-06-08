class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), l = 0, r = n-1, less = 0, greater = n-1;
        vector<int> ans(n);

        while(l < n){
            if(nums[l] < pivot){
                ans[less] = nums[l];
                less++;
            }
            if(nums[r] > pivot){
                ans[greater] = nums[r];
                greater--;
            }

            l++; 
            r--;
        }

        while(less <= greater){
            ans[less++] = pivot;
        }

        return ans;
    }
};