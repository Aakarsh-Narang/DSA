class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = 1, n = nums.size(), cnt = 0;

        while(j < n){
            if(i == j){
                j++;
                continue;
            }
            if(nums[j] - nums[i] == k){
                cnt++;
                i++;
                j++;
                while(i < n && nums[i] == nums[i-1]){
                    i++;
                }
                while(j < n && nums[j] == nums[j-1]){
                    j++;
                }
            }
            else if(nums[j] - nums[i] > k){
                i++;
            }
            else{
                j++;
            }
        }

        return cnt;
    }
};