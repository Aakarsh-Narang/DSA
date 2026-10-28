class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<long long> dist(n, 1e18), ways(n, 0);
        vector<vector<pair<long long,long long>>> adj(n);

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;


        for(auto& e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }


        dist[0] = 0;
        pq.push({0, 0}); // {Dist, node}
        ways[0] = 1;

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& [nbr, wt] : adj[node]){
                if(dist[nbr] == d + wt){
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
                else if(dist[nbr] > d + wt){
                    ways[nbr] = ways[node];
                    dist[nbr] = d + wt;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return ways[n-1];
    }
};