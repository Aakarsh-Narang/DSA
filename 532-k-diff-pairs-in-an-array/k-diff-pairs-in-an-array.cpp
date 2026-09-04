class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> st;

        int i = 0, j = 1, n = nums.size(), cnt = 0;

        while(j < n){
            if(i == j){
                j++;
                continue;
            }
            if(nums[j] - nums[i] == k){
                st.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if(nums[j] - nums[i] > k){
                i++;
            }
            else{
                j++;
            }
        }

        return st.size();
    }
};