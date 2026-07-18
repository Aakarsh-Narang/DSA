class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dq.push_back(0);

        for(int i = 1; i < n; i++){
            // Popping out of scope elements/ indices from front
            while(!dq.empty() && i - dq.front() > k){
                dq.pop_front();
            }
            
            dp[i] =  nums[i] + dp[dq.front()];

            // Popping all smaller values/ sums from the back
            while(!dq.empty() && dp[i] > dp[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return dp[n-1];
    }
};