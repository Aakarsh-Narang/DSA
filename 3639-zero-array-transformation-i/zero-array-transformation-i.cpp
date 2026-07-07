class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), currSum = 0;
        vector<int> diff(n+1, 0);

        // Build diff array
        for(auto& q : queries){
            diff[q[0]] += 1;
            diff[q[1]+1] -= 1;
        }

        // Update nums as per max operation allowed
        for(int i = 0; i < n; i++){
            currSum += diff[i];
            nums[i] = max(0, nums[i] - currSum);
        }

        if(*max_element(nums.begin(), nums.end()) > 0) return false;
        return true;
    }
};