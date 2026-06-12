class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(maxSoFar < 0){  // nums[i] > maxSoFar + nums[i]
                maxSoFar = nums[i];
            }
            else{
                maxSoFar += nums[i];
            }

            maxSum = max(maxSum, maxSoFar);
        }

        return maxSum;
    }
};