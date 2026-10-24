class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans = 0, n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        long long curr = 0, target = totalSum - x;
        int l = 0, r = 0;
        if(target == 0) return n;
        if(target < 0) return -1;

        while(r < n){
            curr += nums[r];

            while(l<=r && curr > target){
                curr -= nums[l];
                l++;
            }
            if(curr == target){
                ans = max(ans, r - l + 1);
            }

            r++;
        }

        if(ans == 0) return -1;
        return (n - ans);
    }
};