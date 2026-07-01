class Solution {
public:
    int dfs(int node, int& n, vector<vector<int>>& adj, vector<int>& time, vector<int>& dp){
        if(dp[node] != -1) return dp[node];

        int maxTime = 0;

        for(auto& nbr : adj[node]){
            maxTime = max(maxTime, dfs(nbr, n, adj, time, dp));
        }

        // For leaf nodes maxTime will stay 0, so they return only their own time
        return dp[node] = maxTime + time[node];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), dp(n, -1);
        int ans = 0;

        for(auto& e : relations){
            adj[e[0]-1].push_back(e[1]-1);
            indegree[e[1]-1]++;
        }

        for(int i = 0; i < n; i++){
            if(!indegree[i]){
                ans = max(ans, dfs(i, n, adj, time, dp));
            }
        }

        return ans;
    }
};