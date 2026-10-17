class Solution {
public:
    int count(vector<int>& nums, int k){
        for(auto& n : nums) n = n % 2;

        int sum = 0, ans = 0, l = 0, n = nums.size(), r = 0;

        while(r < n){
            sum += nums[r];

            while(sum > k){
                sum -= nums[l++];
            }
            ans += (r-l+1);
            r++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k-1);
    }
};