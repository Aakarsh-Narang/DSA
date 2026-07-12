class Solution {
public:
    bool dfs(int node, int target, vector<vector<int>>& adj, vector<bool>& vis){
        if(node == target) return true;

        vis[node] = 1;
        for(auto& nbr : adj[node]){
            if(!vis[nbr])
                if(dfs(nbr, target, adj, vis))
                    return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0; 
        for(auto& e : edges){ 
            n = max({n, e[0], e[1]}); 
        }
        vector<int> ans;
        vector<vector<int>> adj(n+1);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            vector<bool> vis(n+1, false);

            if (dfs(u, v, adj, vis))
                ans = e;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return ans;
    }
};