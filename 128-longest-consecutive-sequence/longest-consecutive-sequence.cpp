class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto& n : nums){
            if(st.count(n-1) || !st.count(n)) continue;
            int len = 0;

            while(st.count(n + len)){
                st.erase(n+len);
                len++;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};