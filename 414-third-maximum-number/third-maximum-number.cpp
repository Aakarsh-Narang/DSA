class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, bool> mp;

        for(int i = 0; i < min(3, (int)nums.size()); i++){
            if(!mp[nums[i]]){
                mp[nums[i]] = true;
                pq.push(nums[i]);
            }
        }

        for(int i = 3; i < nums.size(); i++){
            if((pq.size() < 3 || nums[i] > pq.top()) && !mp[nums[i]]){
                pq.push(nums[i]);
                mp[nums[i]] = true;
            }
            while(pq.size() > 3) pq.pop();
        }
        if(pq.size() < 3) return *max_element(nums.begin(), nums.end());
        return pq.top();
    }
};