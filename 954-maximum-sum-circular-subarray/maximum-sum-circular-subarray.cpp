class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 1e7, n = nums.size(), last = 0, minSum = INT_MAX, wholeSum = 0, ans = -1e7;

        for(int i = 0; i < n; i++){
            sum = min(nums[i], sum + nums[i]);
            minSum = min(minSum, sum);
            wholeSum += nums[i];
        }
        sum = -1e7;
        for(int i = 0; i < n; i++){
            sum = max(nums[i], sum + nums[i]);
            ans = max(ans, sum);
        }
        if(wholeSum == minSum) return max(ans, *max_element(nums.begin(), nums.end()));
        return max(wholeSum - minSum, ans);
    }
};