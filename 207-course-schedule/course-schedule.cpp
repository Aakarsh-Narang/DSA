class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto& pre: prerequisites){
            int a = pre[0], b = pre[1];
            indeg[a]++;
            adj[b].push_back(a);
        }

        vector<int> topo;
        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto& nbr : adj[node]){
                indeg[nbr]--;
                if(indeg[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return topo.size() == numCourses;
    }
};