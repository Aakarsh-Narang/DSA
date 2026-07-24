class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<int> dist(n+1, 1e7);
        dist[k] = 0;
        dist[0] = 0;

        for(int i = 0; i < n; i++){
            for(auto& e : times){
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        if(*max_element(dist.begin(), dist.end()) == 1e7) return -1;
        return *max_element(dist.begin(), dist.end());
    }
};