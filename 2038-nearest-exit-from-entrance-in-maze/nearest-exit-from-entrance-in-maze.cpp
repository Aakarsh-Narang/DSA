class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dir[] = {-1, 0, 1, 0, -1};
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        int sx = entrance[0], sy = entrance[1];
        q.push({sx, sy});
        dist[sx][sy] = 0;

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nr = r + dir[k], nc = c + dir[k+1];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] != '+' && dist[nr][nc] == -1){
                        q.push({nr, nc});
                        dist[nr][nc] = dist[r][c] + 1;
                        if(nr == 0 || nc == 0 || nr == m-1 || nc == n-1) return dist[nr][nc];
                    }
                }
            }
        }
        return -1;
    }
};