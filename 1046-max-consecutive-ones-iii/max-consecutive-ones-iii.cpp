class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), currZeroes = 0, ans = 0;;

        while(r < n){
            currZeroes += (nums[r] == 0);
            while(currZeroes > k && l <= r){
                currZeroes -= (nums[l] == 0);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};