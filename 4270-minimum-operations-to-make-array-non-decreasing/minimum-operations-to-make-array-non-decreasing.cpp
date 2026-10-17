class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long total = 0, n = nums.size();

        for(int i = 1; i < n; i++){
            // We propagate the addition to entire array, so when prev is made equal/ greater than its prev elements 
            // So we just have to curr equal to it's prev element, it will automatically match the others before it
            total += max(0, nums[i-1] - nums[i]);
        }
        return total;
    }
};