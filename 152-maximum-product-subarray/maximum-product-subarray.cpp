class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0], minSoFar = nums[0], maxProduct = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(nums[i], nums[i] * maxSoFar);
            minSoFar = min(nums[i], nums[i] * minSoFar);

            maxProduct = max(maxProduct, maxSoFar);
        }

        return maxProduct;
    }
};