class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(auto& n: nums){
            mp[n]++;
        }
        int ans = mp[1] % 2 == 0 ? mp[1] - 1 : mp[1];
        mp.erase(1);

        for(auto& [num, freq] : mp){
            int curr = 0;
            long long n = num;
            for(; (mp.count(n) && mp[n] > 1); n = n*n){
                curr += 2;
            }
            curr += ((mp.count(n) && mp[n]==1) ? 1 : -1);  // The largest element that my have freq of 1 or 0
            ans = max(ans, curr);
        }

        return ans;
    }
};