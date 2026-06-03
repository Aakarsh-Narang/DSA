class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int minSoFar = 1e9, maxSoFar = 0, minIndx = 0, maxIndx = 0;
        int l = 0, r = indexDifference, n = nums.size();

        while(r < n){
            if(nums[l] < minSoFar){
                minIndx = l;
                minSoFar = nums[l];
            }
            if(nums[l] > maxSoFar){
                maxIndx = l;
                maxSoFar = nums[l];
            }

            if(abs(nums[r] - minSoFar) >= valueDifference){
                return {minIndx,r};
            }
            if(abs(nums[r] - maxSoFar) >= valueDifference){
                return {maxIndx, r};
            }

            l++;
            r++;
        }

        return {-1,-1};
    }
};