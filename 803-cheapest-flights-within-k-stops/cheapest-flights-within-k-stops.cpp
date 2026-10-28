class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> minStops(n, INT_MAX);

        for(auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        using state = tuple<int, int, int>;  // Dist, node, No_of_stops
        priority_queue<state, vector<state>, greater<>> pq;

        pq.push({0, src, 0});

        while(!pq.empty()){
            auto[d, node, stops] = pq.top();
            pq.pop();
            if(node == dst) return d;
            if(minStops[node] < stops || stops > k) continue;
            minStops[node] = stops;

            for(auto& [nbr, w] : adj[node]){
                pq.push({d + w, nbr, stops+1});
            }
            
        }
        return -1;
    }
};