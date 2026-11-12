class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), inc = 1, dec = 1, ans = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec = 1;
                ans = max(ans, inc);
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;
                ans = max(ans, dec);
            }
            else{
                inc = 1;
                dec = 1;
            }
        }

        return ans;
    }
};