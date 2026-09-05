class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = min(suffix[i+1], nums[i]);
        }

        int maxSoFar = nums[0];
        for(int i = 0; i < n; i++){
            maxSoFar = max(maxSoFar, nums[i]);
            if(maxSoFar - suffix[i] <= k) return i;
        }
        return -1;
    }
};