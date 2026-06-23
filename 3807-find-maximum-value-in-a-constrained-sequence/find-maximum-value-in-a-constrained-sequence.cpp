class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> left(n, 0);

        unordered_map<int, int> mp;
        for(auto& r: restrictions){
            mp[r[0]] = r[1];
        }
        mp[0] = 0;


        // Left iteration
        for(int i = 1; i < n; i++){
            if(mp.count(i)){
                left[i] = min(mp[i], left[i-1] + diff[i-1]);
                continue;
            }

            left[i] = left[i-1] + diff[i-1];
        }


        // Right iteration
        for(int i = n-2; i >= 0; i--){
            if(mp.count(i)){
                left[i] = min({mp[i], left[i], left[i+1] + diff[i]});
                continue;
            }

            left[i] = min(left[i], left[i+1] + diff[i]);
        }

        return *max_element(left.begin(), left.end());
    }
};