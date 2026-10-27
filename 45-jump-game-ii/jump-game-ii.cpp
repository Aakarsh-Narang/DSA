class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, currEnd = 0, jumps = 0;

        for(int i = 0; i < nums.size(); i++){
            farthest = max(farthest, i + nums[i]);

            if(currEnd == i && i != nums.size()-1){
                currEnd = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};