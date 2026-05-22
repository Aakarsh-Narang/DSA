class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // Maintain monotonicity: From back remove all smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);

            // Pop expired or out of window elements from front
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();

            // Build Answer Array
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};