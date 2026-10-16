class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto& n : st){
            if(st.count(n-1)) continue;
            int len = 0;

            while(st.count(n + len)){
                len++;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};