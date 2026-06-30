class Solution {
public:
    int toposort(vector<vector<int>>& adj, vector<int>& quiet, vector<int>& ans, int node){
        int n = quiet.size();
        if(ans[node] != -1) return ans[node];
        ans[node] = node;

        for(auto& nbr : adj[node]){
            int curr = toposort(adj, quiet, ans, nbr);
            if(quiet[ans[node]] > quiet[curr])
                ans[node] = curr;
        }

        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n, -1);

        for(auto& e : richer){
            adj[e[1]].push_back(e[0]);  // edges reversed : Poorer -> Richer
        }

        for(int i = 0; i < n; i++){
            if(ans[i] == -1)
                toposort(adj, quiet, ans, i);
        }

        return ans;
    }
};