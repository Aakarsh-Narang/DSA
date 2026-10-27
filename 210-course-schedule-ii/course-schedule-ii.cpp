class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& p : prerequisites){
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto& nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }
        }

        if(ans.size() != numCourses) return {};

        return ans;
    }
};