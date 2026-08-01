class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        // Min-Heap stores: tuple<cost, node, stops_taken>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Tracks the minimum stops used to reach a node so far
        vector<int> minStops(n, INT_MAX);

        pq.push({0, src, 0});

        while(!pq.empty()){
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(minStops[node] > stops)
                minStops[node] = stops;
            
            else continue;
            

            if(stops > k) continue;

            for(auto& [nbr, wt] : adj[node]){
                pq.push({cost + wt, nbr, stops + 1});
            }   
        }

        return -1;
    }
};