class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>> pq;   // {weight, node}
        vector<vector<pair<int, int>>> adj(n);
        int ans;
        vector<int> dist(n,1e7);

        for(auto& e : times){
            e[0]--;
            e[1]--;
            adj[e[0]].push_back({e[1], e[2]});
        }
        k--;
        
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();

            for(auto& e : adj[node]){
                auto [nbr, w] = e;

                if(dist[nbr] == -1 || w + wt < dist[nbr]){
                    dist[nbr] = w + wt;
                    pq.push({w+wt, nbr});
                }
            }
        }   

        ans = *max_element(dist.begin(), dist.end());
        if(ans == 1e7) return -1;
        return ans;
    }
};