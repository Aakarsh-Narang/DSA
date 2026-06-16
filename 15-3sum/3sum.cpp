class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int target = -nums[i];
            int start = i+1, end = nums.size()-1;

            while(start < end){
                if((nums[start] + nums[end]) == target){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;

                    // Check with previously used values
                    while(start < (nums.size()-1) && nums[start] == nums[start-1]) start++;
                    while(end > i && nums[end] == nums[end+1]) end--;
                }
                else if((nums[start] + nums[end]) > target){
                    end--;
                }
                else{
                    start++;
                }   
            }
        }

        return ans;
    }
};