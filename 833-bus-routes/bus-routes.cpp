class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, unordered_set<int>> busMap, routeMap;
        int n = routes.size();
        vector<bool> vis(n, false);
        unordered_set<int> visStops;

        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                busMap[stop].insert(i);
                routeMap[i].insert(stop);
            }
        }

        queue<pair<int, int>> q; // {stop, busesTaken}

        for (int route : busMap[source]) {
            vis[route] = true;

            for (int stop : routeMap[route]) {
                if (!visStops.count(stop)) {
                    visStops.insert(stop);
                    q.push({stop, 1});
                }
            }
        }

        while (!q.empty()) {
            auto [stop, cnt] = q.front();
            q.pop();

            if (stop == target) return cnt;

            for (int route : busMap[stop]) {
                if (vis[route]) continue;
                vis[route] = true;

                for (int nextStop : routeMap[route]) {
                    if (!visStops.count(nextStop)) {
                        visStops.insert(nextStop);
                        q.push({nextStop, cnt + 1});
                    }
                }
            }
        }

        return -1;
    }
};