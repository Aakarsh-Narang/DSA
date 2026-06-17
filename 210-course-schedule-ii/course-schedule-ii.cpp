class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0), ans;
        queue<int> q;
        
        for(auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto& nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};