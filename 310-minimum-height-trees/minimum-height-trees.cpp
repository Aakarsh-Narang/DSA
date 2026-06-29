class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 2) return {0,1};
        if(n==1) return {0};
        int cnt = n;
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        vector<bool> processed(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            indeg[e[0]]++;
            indeg[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1) {
                q.push(i);
                indeg[i]--;
            }
        }
        q.push(-1);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // cout <<node<<" ";

            if(node == -1){
                if(cnt <=2) break;
                q.push(-1);
                continue;
            }

            cnt--; // keeps a track of how many nodes with indeg > 1 exist or have not been removed
            processed[node] = 1;
           
            for (auto& nbr : adj[node]) {
                indeg[nbr]--;
                if (indeg[nbr] == 1) {
                    q.push(nbr);
                    indeg[nbr]--;
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if (!processed[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    
    }
};