class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> dq;

        dp[0]= nums[0];
        dq.push_back(0);

        for(int i = 1; i < n; i++){
            // Pop all expired ranges
            while(!dq.empty() && (i - dq.front()) > k)
                dq.pop_front();

            dp[i] = nums[i] + max(0, dp[dq.front()]);

            // Pop all smaller Sums from the back
            while(!dq.empty() && dp[dq.back()] < dp[i]) 
                dq.pop_back();

            dq.push_back(i);
        }

        return *max_element(dp.begin(), dp.end());
    }
};