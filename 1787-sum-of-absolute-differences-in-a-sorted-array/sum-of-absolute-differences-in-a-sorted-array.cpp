class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0), ans(n);

        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        for(int i = 0; i < n; i++){
            int prev = (nums[i] * i) - prefix[i];
            int next = (prefix[n] - prefix[i+1]) - (nums[i] * (n - i - 1));
            ans[i] = (prev + next);
        }

        return ans;
    }
};

//    2, 3, 5
// 0, 2, 5, 10