class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), first0 = 0;
        while(first0 < n && nums[first0] != 0) first0++;
        if(first0 >= n) return;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0 && i > first0){
                swap(nums[i], nums[first0]);
            }
            while(first0 < n && nums[first0] != 0) first0++;
        }
    }
};