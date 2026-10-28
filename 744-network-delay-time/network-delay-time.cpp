class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto& t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, 1e8);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(dist[u] < d) continue;
            for(auto& [nbr, w] : adj[u]){
                if(d + w < dist[nbr]){
                    dist[nbr] = d + w;
                    pq.push({dist[nbr], nbr});
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] >= 1e8) return -1;
            res = max(dist[i], res);
        }

        return res;
    }
};