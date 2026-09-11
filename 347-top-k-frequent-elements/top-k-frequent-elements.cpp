class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(auto& n : nums) mp[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(auto& [num, freq] : mp){
            pq.push({freq, num});

            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};