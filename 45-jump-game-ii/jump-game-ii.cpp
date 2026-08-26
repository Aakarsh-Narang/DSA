class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, currEnd = 0, jumps = 0, n = nums.size();

        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, nums[i] + i);

            if(i == currEnd){
                currEnd = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};