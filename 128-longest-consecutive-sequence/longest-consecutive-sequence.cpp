class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for(auto n : nums){
            if(numSet.count(n-1)) continue;
            int length = 0;
            while(numSet.count(n + length) >= 1){
                numSet.erase(n + length);
                length++;
            }
            longest = max(longest, length);
        }

        return longest;
    }
};