class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<long long> ans;

        vector<long long> prefix(n+1, 0LL);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(auto& q : queries){
            int indx = lower_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long deficit = (indx * 1LL * q) - (prefix[indx]);
            long long surplus = (prefix[n] - prefix[indx]) - 1LL * (n - indx) * q;

            ans.push_back(deficit + surplus);
        }

        return ans;
    }
};