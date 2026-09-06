class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;

        // Group indices having the same value
        for(int i = 0; i < n; i++)
            groups[nums[i]].push_back(i);

        vector<long long> res(n);

        for(auto& p : groups){
            vector<int>& group = p.second;
            int m = group.size();

            // Prefix sum of indices
            vector<long long> prefix(m + 1, 0);

            for(int i = 0; i < m; i++)
                prefix[i + 1] = prefix[i] + group[i];

            for(int i = 0; i < m; i++){
                long long x = group[i];

                // Distance to indices on the left
                long long left = 1LL * x * i - prefix[i];

                // Distance to indices on the right
                long long right = (prefix[m] - prefix[i + 1]) - 1LL * x * (m - i - 1);

                res[x] = left + right;
            }
        }

        return res;
    }
};