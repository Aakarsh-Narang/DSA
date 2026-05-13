class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] <= mid)
                    cnt++;
            }
            if(cnt > mid) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};