class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        priority_queue<int> pq;
        int operations = 0, ns = nums.size(), qs = queries.size();
        vector<int> diff(ns + 1, 0);

        for(int i = 0, j = 0; i < ns; i++){
            operations += diff[i];  // Update any closing operations

            // Push all operations starting till i
            while(j < qs && queries[j][0] <= i){
                pq.push(queries[j][1]);
                j++;
            }

            // Pop just as many operations needed to settle nums[i]
            while(operations < nums[i] && !pq.empty() && pq.top() >= i){
                int closing = pq.top();
                pq.pop();
                diff[closing + 1] -= 1;
                operations++;
            }
            if(operations < nums[i]) return -1;
        } 
        return pq.size();
    }
};