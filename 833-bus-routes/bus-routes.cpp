class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        // BusMap : {BusStop -> Routes}
        // RouteMap : {Route -> BusStops}
        unordered_map<int, unordered_set<int>> busMap, routeMap;
        int n = routes.size();
        unordered_set<int> visStops, visRoutes;
        
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
                if(!visStops.count(stop)){
                    visStops.insert(stop);
                    q.push({stop, 1});
                }
            }
            visRoutes.insert(route);
        }

        while(!q.empty()){
            auto [stop, cnt] = q.front();
            q.pop();

            if(stop == target) return cnt;

            for(auto& route : busMap[stop]){
                if(visRoutes.count(route)) continue;
                for(auto& stop : routeMap[route]){
                    if(!visStops.count(stop)){
                        visStops.insert(stop);
                        q.push({stop, cnt+1});
                    }
                }
                visRoutes.insert(route);
            }
        }

        return -1;
    }
};