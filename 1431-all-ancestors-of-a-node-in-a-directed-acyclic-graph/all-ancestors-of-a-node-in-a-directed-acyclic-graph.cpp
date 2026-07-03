class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<unordered_set<int>>& ans){
        for(auto& nbr : adj[node]){
            if(ans[nbr].empty())
                dfs(nbr, adj, ans);

            ans[node].insert(ans[nbr].begin(), ans[nbr].end());
            ans[node].insert(nbr);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> ans(n);
        vector<int> indeg(n, 0);

        for(auto& e : edges){
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }

        for(int i = 0; i < n; ++i){
            if(!indeg[i])
                dfs(i, adj, ans);
        }

        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            res[i] = vector<int>(ans[i].begin(), ans[i].end());
            sort(res[i].begin(), res[i].end());
        }

        return res;
    }
};