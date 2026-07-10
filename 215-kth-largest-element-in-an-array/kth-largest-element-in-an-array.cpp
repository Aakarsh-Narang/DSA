class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < min(k, (int)nums.size()); i++) pq.push(nums[i]);

        for(int i = k; i< nums.size(); i++){
            if(pq.top() < nums[i]) pq.push(nums[i]);
            while(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};