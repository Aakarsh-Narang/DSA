class Solution {
public:
    // cap -> max amount of money allowed to be robbed
    bool canRob(vector<int>& nums, int k, int cap){
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0] <= cap;

        for(int i = 1; i < nums.size(); i++){
            int notRob = dp[i - 1];
            int rob = 0;

            if(nums[i] <= cap) {
                rob = 1;
                if(i >= 2)
                    rob += dp[i - 2];
            }

            dp[i] = max(rob, notRob);
        }

        return dp[nums.size()-1] >= k;
    }
    // bool canRob(vector<int>& nums, int k, int cap) {
    //     int count = 0;

    //     for(int i = 0; i < nums.size();) {
    //         if(nums[i] <= cap) {
    //             count++;
    //             i += 2;   // rob this, so skip adjacent house
    //         }
    //         else {
    //             i++;
    //         }

    //         if(count >= k)
    //             return true;
    //     }

    //     return false;
    // }
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        int ans = hi;

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;

            if(canRob(nums, k, mid)){
                ans = mid; 
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};