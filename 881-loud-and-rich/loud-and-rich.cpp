class Solution {
public:
    vector<int> toposort(vector<vector<int>>& adj, vector<int>& quiet){
        int n = quiet.size();
        vector<int> indeg(n, 0), ans(n);
        iota(ans.begin(), ans.end(), 0);
        
        for(auto& v : adj){
            for(auto& nbr : v){
                indeg[nbr]++;
            }
        }

        queue<int> q;
        // Push initial elements with indeg == 0
        for(int i = 0; i < n; i++){
            // cout << indeg[i]<<" ";
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        // Expand to rest of the graph from the initail nodes
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& nbr : adj[node]){
                if(quiet[ans[node]] < quiet[ans[nbr]]) ans[nbr] = ans[node];
                indeg[nbr]--;
                if(!indeg[nbr]) q.push(nbr);
            }

        }

        return ans;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);

        for(auto& e : richer){
            adj[e[0]].push_back(e[1]);
        }

        return toposort(adj, quiet);
    }
};