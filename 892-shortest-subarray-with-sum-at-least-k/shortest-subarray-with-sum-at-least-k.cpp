class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;

        deque<int> dq;
        vector<int> prefixSum(n+1, 0);

        dq.push_front(0);

        for(int i = 1; i <= n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1]; 
            
            // Find smallest possible subarray size
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Remove all larger prefixSum indices from the end, 
            // they become useless when we find smaller values later
            while(!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]){
                dq.pop_back();
            }

            // Push current PrefixSum index at correct place
            dq.push_back(i);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};