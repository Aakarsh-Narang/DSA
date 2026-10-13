class Solution {
public:
    int count(vector<int>& nums, int diff) {
        int l = 0, r = 0, n = nums.size(), cnt = 0;

        while (r < n) {
            while (nums[r] - nums[l] > diff)
                l++;

            cnt += r - l;
            r++;
        }

        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums[n-1] - nums[0], ans = -1;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            int cnt = count(nums, mid);

            if(cnt >= k){
                ans = mid;
                hi = mid - 1;
            } 
            else lo = mid + 1;
        }

        return ans;
    }
};