class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], i, 0});
        }

        while(k--){
            if(k == 0) return get<0>(pq.top());

            auto [val, r, c] = pq.top();
            pq.pop();
            
            if(c + 1 < n) pq.push({matrix[r][c+1], r, c+1});
        }

        return -1;
    }
};