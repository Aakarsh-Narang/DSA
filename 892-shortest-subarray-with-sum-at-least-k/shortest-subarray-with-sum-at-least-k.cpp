class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;

        if(n == 1) return nums[0] >= k ? 1 : -1;
        deque<int> dq;
        vector<int> prefixSum(n, 0);

        // handling the 0th Index
        prefixSum[0] = nums[0];
        dq.push_front(0);
        if(prefixSum[0] >= k) ans = min(ans, 1);

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i]; 
            
            // Find smallest possible subarray size
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Bcz we skip the -1 index or 0 initial sum here (like we do in HashMap solutions)
            if(prefixSum[i] >= k) ans = min(ans, i+1);

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