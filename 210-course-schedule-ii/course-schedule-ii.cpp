class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0), ans;
        vector<vector<int>> adj(numCourses);

        for(auto& v : prerequisites){
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& nbr : adj[node]){
                indeg[nbr]--;
                if(indeg[nbr] == 0) q.push(nbr);
            }

            ans.push_back(node);
        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};