class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        // len -> carpetLen
        int n = tiles.size(), l = 0, r = 0;
        int cover = 0, ans = 0;

        sort(tiles.begin(), tiles.end());
        while(r < n && l < n){
            if(tiles[l][0] + len > tiles[r][1]){
                cover += (tiles[r][1] - tiles[r][0] + 1);
                ans = max(ans, cover);
                r++;
            }
            else{
                int partial = max(0, tiles[l][0] + len - tiles[r][0]);
                ans = max(ans, cover + partial);
                cover -= (tiles[l][1] - tiles[l][0] + 1);
                l++;
            }
        }
        return ans;
    }
};