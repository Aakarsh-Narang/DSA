class Solution {
public:
    void dfs(int node, vector<int>& nodes, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        nodes.push_back(node);
        for(auto& nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr, nodes, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> nodes;
                bool flg = 1;
                dfs(i, nodes, adj, vis);
                int totalNodes = nodes.size();
                for(auto& n : nodes){
                    // cout << n << " ";
                    if(adj[n].size() != totalNodes-1) flg = 0;
                }
                // cout<<endl;
                if(flg) cnt++;
            }
        }

        return cnt;
    }
};