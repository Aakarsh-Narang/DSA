class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> left(n, 1e9);

        for(auto& r: restrictions){
            left[r[0]] = r[1];
        }
        left[0] = 0;


        // Left iteration
        for(int i = 1; i < n; i++){
            left[i] = min(left[i], left[i-1] + diff[i-1]);
        }


        // Right iteration
        for(int i = n-2; i >= 0; i--){
            left[i] = min(left[i], left[i+1] + diff[i]);
        }

        return *max_element(left.begin(), left.end());
    }
};