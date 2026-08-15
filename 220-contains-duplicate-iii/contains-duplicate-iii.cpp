class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        multiset<int> st;

        for(int i = 0; i < n; i++){
            if(i > indexDiff){
                st.erase(nums[i - indexDiff - 1]);
            }
            int lr = nums[i] - valueDiff, ur = nums[i] + valueDiff;

            auto it = st.lower_bound(lr);

            if (it != st.end() && *it <= ur)
                return true;
            st.insert(nums[i]);
        }

        return false;
    }
};