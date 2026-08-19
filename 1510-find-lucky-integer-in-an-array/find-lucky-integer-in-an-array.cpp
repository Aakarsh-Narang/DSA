class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int ans = -1;

        for(auto& n : arr) mp[n]++;

        for(auto& [key, val] : mp){
            if(key == val) ans = max(ans, key);
        }

        return ans;
    }
};