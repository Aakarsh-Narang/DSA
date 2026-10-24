class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        // BusMap : {BusStop -> Routes}
        // RouteMap : {Route -> BusStops}
        unordered_map<int, unordered_set<int>> busMap, routeMap;
        int n = routes.size();
        vector<bool> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            auto r = routes[i];
            for(auto& busStop : r){
                busMap[busStop].insert(i);
                routeMap[i].insert(busStop);
            }
        }
     
        queue<pair<int, int>> q; // {route, stop}
        for(auto& route : busMap[source]){
            for(auto& stop : routeMap[route]){
                q.push({stop, 1});
            }
            vis[route] = 1;
        }

        while(!q.empty()){
            auto [stop, cnt] = q.front();
            q.pop();

            if(stop == target) return cnt;

            for(auto& route : busMap[stop]){
                if(vis[route]) continue;
                for(auto& stop : routeMap[route]){
                    q.push({stop, cnt+1});
                }
                vis[route] = 1;
            }
        }

        return -1;
    }
};