class Solution {
public:
    unordered_map<int, unordered_set<int>> mp;

    vector<int> toposort(int numCourses, vector<vector<int>>& prerequisites){
        vector<int>indeg(numCourses, 0), ans;
        vector<vector<int>> adj(numCourses);

        for(auto& e : prerequisites){
            // the wording is opposite in this problem as compared to earler Course Schedule Problems
            // Here we have an edge : a -> b; 'a' in independent here
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i]== 0)
                q.push(i);
            mp[i].insert(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto& nbr : adj[node]){
                indeg[nbr]--;
                mp[nbr].insert(mp[node].begin(), mp[node].end());
                if(!indeg[nbr]) q.push(nbr);
            }
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> topo = toposort(numCourses, prerequisites);
        int n = topo.size();
        vector<bool> ans;

        for(auto& q : queries){
            int u = q[0], v = q[1];
            if(mp[v].count(u)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};