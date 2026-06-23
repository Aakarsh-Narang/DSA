class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> left(n, 0), right(n, 0);
        int ans;

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
        right[n-1] = left[n-1];
        for(int i = n-2; i >= 0; i--){
            if(mp.count(i)){
                right[i] = min(mp[i], right[i+1] + diff[i]);
                continue;
            }

            right[i] = right[i+1] + diff[i];
        }

        // use min at each index
        for(int i = 0; i < n; i++){
            ans = max(ans, min(left[i], right[i]));
        }
        
        return ans;
    }
};