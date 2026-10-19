class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long len = 1, n = nums.size(), l = 0, r = 1, curr = 0;

        while(r < n){
            curr += (nums[r] - nums[r-1])*(r-l);  //Since elements before r-1 have been made equal to nums[r-1]
            while(curr > k){
                curr -= (nums[r]-nums[l]);  // Entire differnce is removed from window
                l++;
            }
            len = max(len, r-l+1);
            r++;
        }

        return len;
    }
};