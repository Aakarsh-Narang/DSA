class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int start, end;
        for(int i = 0; i<nums.size(); i++){
            start = nums[i], end = nums[i];
            string curr = to_string(start);

            while(i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            end = nums[i];
            if(start != end) {
                ans.push_back(curr + "->" + to_string(end));
            }
            else {
                ans.push_back(to_string(start));
            }
        }
        return ans;
    }
};