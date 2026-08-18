class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads){
        vector<int> ans;
        vector<vector<tuple<long long, long long, long long>>> adj(n);

        for(auto& e : roads){
            long long u = e[0], v = e[1];
            long long cost = e[2], tax = e[3];

            adj[u].push_back({v, cost, tax});
            adj[v].push_back({u, cost, tax});
        }

        for(int i = 0; i < n; i++){
            vector<long long> dist(n, 2e9);
            dist[i] = 0;
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;  //{cost, node}

            pq.push({0, i});
        
            // Phase 1: Shortest paths from source to all nodes
            while(!pq.empty()){
                auto [cost, node] = pq.top();
                pq.pop();

                if(dist[node] < cost) continue;

                for(auto &[nbr, price, tax] : adj[node]){
                    if(dist[node] + price <= dist[nbr]){
                        dist[nbr] = dist[node] + price;
                        pq.push({dist[node] + price, nbr});
                    }
                }
            }

            for(int k = 0; k < n; k++){
                dist[k] += prices[k];
                
                pq.push({dist[k], k});
            }
       
            dist.assign(n, 2e9);
            // Phase 2: Find shortest path back to source
            while(!pq.empty()){
                auto [cost, node] = pq.top();
                pq.pop();

                if(node == i){
                    ans.push_back(cost);
                    break;
                }

                if(dist[node] < cost) continue;

                for(auto& [nbr, price, tax] : adj[node]){
                    if(cost + tax * price < dist[nbr]){
                        dist[nbr] = cost + tax * price;
                        pq.push({cost + tax * price, nbr});
                    }
                }
            }
        }

        return ans;
    }
};