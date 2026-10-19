class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long len = 1, n = nums.size(), l = 0, r = 1, curr = 0;

        while(r < n){
            curr += (nums[r] - nums[r-1])*(r-l);
            while(curr > k){
                curr -= (nums[r]-nums[l]);
                l++;
            }
            len = max(len, r-l+1);
            // cout << l <<" "<<r << " "<<curr<<endl;
            r++;
        }

        return len;
    }
};