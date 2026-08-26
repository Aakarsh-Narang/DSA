class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndx = 0, n = nums.size();

        for(int i = 0; i < nums.size(); i++){
            maxIndx = max(maxIndx, i + nums[i]);

            if(maxIndx >= n-1) return true;
            if(i >= maxIndx) return false;
        }

        return false;
    }
};