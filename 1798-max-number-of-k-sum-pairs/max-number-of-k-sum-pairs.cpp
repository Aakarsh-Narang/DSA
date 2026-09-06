class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pairs = 0;

        for(auto& n : nums) mp[n]++;

        for(int& n: nums){
            int cnt1 = mp[n];
            int cnt2 = mp[k - n]; 
            if(cnt1 <= 0 || cnt2 <= 0 || n >= k) continue;
            int toUse = min(cnt1, cnt2);

            if(k == n*2){
                toUse /= 2;
                pairs += toUse;
                mp[n] -= toUse*2;
            }
            else{
                mp[n] -= toUse;
                mp[k - n] -= toUse;
                pairs += toUse;
            }
        }

        return pairs;
    }
};