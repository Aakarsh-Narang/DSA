class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(auto n : numSet){
            if(numSet.count(n-1)) continue;
            int length = 1;
            while(numSet.count(n + length) >= 1){
                length++;
                // cout << length <<" ";
            }
            longest = max(longest, length);
        }

        return longest;
    }
};