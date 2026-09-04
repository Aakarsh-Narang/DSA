class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0, i = 0, j = n-1;

        while(i < j){
            if(nums[i] + nums[j] < target){
                ans += (j - i);
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};