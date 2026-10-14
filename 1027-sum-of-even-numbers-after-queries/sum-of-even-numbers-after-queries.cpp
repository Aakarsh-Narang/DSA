class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;

        for(auto& n : nums){
            if(n % 2 == 0)
                sum += n;
        }

        for(auto& q : queries){
            int val = q[0], indx = q[1];

            if(nums[indx] % 2 == 0) sum -= nums[indx];

            nums[indx] += val;

            if(nums[indx] % 2 == 0) sum += nums[indx];

            ans.push_back(sum);
        }

        return ans;
    }
};