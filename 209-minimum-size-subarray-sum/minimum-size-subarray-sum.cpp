class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int l=0,r=0,n=nums.size(),sum=0,len=n+1;
        for(r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                len=min(len,r-l+1);
                sum-=nums[l++];
            }
        }
        if(len==n+1)
            return 0;
        return len;
    }
};