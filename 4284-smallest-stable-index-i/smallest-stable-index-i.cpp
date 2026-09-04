class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), curr = nums[0], ans = -1;
        vector<int> prefix(n, 0), suffix(n, 0);

        for(int i = 0; i < n; i++){
            curr = max(curr, nums[i]);
            prefix[i] = curr;
        }
        curr = nums[n-1];
        
        for(int i = n-1; i >= 0; i--){
            curr = min(curr, nums[i]);
            suffix[i] = curr;
            if(prefix[i] - suffix[i] <= k) ans = i;
        }

        return ans;
    }
};