class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, curr = 0, n = grid[0].size();

        for(auto& row : grid){
            int l = 0, r = n-1, mid;
            curr = n;

            while(l <= r){
                mid = (r - l) / 2 + l;
                if(row[mid] >= 0){
                    l = mid + 1;
                } 
                else{
                    curr = mid;
                    r = mid-1;
                }
            } 
            
            ans += (n - curr);
        } 

        return ans;
    }
};