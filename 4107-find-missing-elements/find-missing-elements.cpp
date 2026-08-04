class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int curr = nums[0], i = 0, n = nums.size();

        while(curr < nums[n-1]){
            while(curr != nums[i]){
                ans.push_back(curr);
                curr++;
            }
            i++;
            curr++;
        }

        return ans;
    }
};