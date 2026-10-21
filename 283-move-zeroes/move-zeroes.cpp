class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr=0;
        for(auto& i:nums)
        {
            if(i!=0)
                swap(i,nums[ptr++]);
        }
    }
};