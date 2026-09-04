class Solution {
public:
    long long maxSum(vector<int>& nums, int cap){
        int  n = nums.size(), i = 0, j = n-1;
        long long ans = 0;

        while(i < j){
            if(nums[i] + nums[j] <= cap){
                ans += (j - i);
                i++;
            }
            else 
                j--;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        return maxSum(nums, upper) - maxSum(nums, lower-1);
    }
};