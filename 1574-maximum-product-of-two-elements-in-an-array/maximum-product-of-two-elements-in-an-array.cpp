class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=0, max2=0, n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i] > nums[max1])
                max1 = i;
        } 
        if(max1 == 0) max2 = 1;
        for(int i =0; i<n; i++){
            if(i != max1 && nums[i] > nums[max2])
                max2 = i;
        }
        return (nums[max1]-1) * (nums[max2]-1);
    }
};