class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int l = 0, r = 0, ans = 0, n = nums.size();

        while(r < n){
            st.insert(nums[r]);
            while(!st.empty() && abs(*st.begin() - *st.rbegin()) > limit){
                // cout << *st.begin() <<" "<<*st.rbegin()<<endl;
                st.erase(st.find(nums[l]));
                l++;
            }
                
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};