class Solution {
public:
    // Prim's Algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int totalCost = 0, n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> vis(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dx = abs(x2 - x1), dy = abs(y2 - y1);
                adj[i].push_back({j, dx + dy});
            }
        }

        pq.push({0, 0});

        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
        
            vis[node] = 1;
            totalCost += wt;

            for(auto& [nbr, wt] : adj[node]){
                if(vis[nbr]) continue;
                pq.push({wt, nbr});
            }
        }

        return totalCost;
    }
};