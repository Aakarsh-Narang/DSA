class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,-1);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});  // Nbr-Cost
        }

        queue<tuple<int,int,int>> q;    // Node-Cost-Stops

        q.push({src,0,0});  //Src itself has 0 cost nd 0 stops
        dist[src]=0;

        while(!q.empty()){
            auto [node, cost, stops]=q.front();
            q.pop();

            if(stops>k) continue;   // No use cheking further

            for(auto& nbr:adj[node]){
                int newCost=cost+nbr.second;
                
                // Checking if cheaper price is available
                if(newCost < dist[nbr.first] || dist[nbr.first]==-1){
                    dist[nbr.first]=newCost;
                    q.push({nbr.first,newCost,stops+1});
                }
                
            }
        }

        return dist[dst];
    }
};