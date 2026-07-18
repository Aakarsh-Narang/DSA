class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans;
        vector<int> dp(n, 0);
        deque<int> dq;

        dp[0]= nums[0];
        dq.push_back(0);
        ans = dp[0];

        for(int i = 1; i < n; i++){
            // Pop all expired ranges
            while(!dq.empty() && (i - dq.front()) > k)
                dq.pop_front();

            dp[i] = max(nums[i], nums[i] + dp[dq.front()]);  // Kadane's Algo
            ans = max(ans, dp[i]);

            // Pop all smaller Sums from the back
            while(!dq.empty() && dp[dq.back()] < dp[i]) 
                dq.pop_back();

            dq.push_back(i);
        }

        return ans;
    }
};