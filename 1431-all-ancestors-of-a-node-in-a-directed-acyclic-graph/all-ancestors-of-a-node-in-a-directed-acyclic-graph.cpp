class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<unordered_set<int>> anc(n);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &nbr : adj[node]) {

                // node itself is an ancestor
                anc[nbr].insert(node);

                // all ancestors of node are also ancestors of nbr
                anc[nbr].insert(anc[node].begin(), anc[node].end());

                if (--indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        vector<vector<int>> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(anc[i].begin(), anc[i].end());
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};