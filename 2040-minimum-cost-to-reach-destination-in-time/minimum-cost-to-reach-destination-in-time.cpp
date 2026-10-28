class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));
        // {Dist, node, time}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;


        pq.push({passingFees[0], 0, 0});
        dist[0][0] = passingFees[0];

        while(!pq.empty()){
            auto [cost, node, currTime] = pq.top();
            pq.pop();

            if(node == n-1) return cost;
            if(cost > dist[node][currTime]) continue;
            
            for(auto& [nbr, time] : adj[node]){
                // newTime = currTime + time
                if(currTime + time > maxTime) continue;

                int newCost = cost + passingFees[nbr];

                if(dist[nbr][currTime + time] > newCost){
                    dist[nbr][currTime + time] = newCost;
                    pq.push({newCost, nbr, currTime + time});
                }
            }
        }

        return -1;
    }
};