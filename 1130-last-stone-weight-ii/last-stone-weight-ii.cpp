class Solution {
public:
    int solve(int index , int curr_sum , int & total_sum , vector<int>&stones , vector<vector<int>>&dp)
    {
      if(index < 0)
        return abs(total_sum - 2 * curr_sum);
      
      if(dp[index][curr_sum] != -1)
        return dp[index][curr_sum];

      int take = solve(index - 1 , curr_sum + stones[index] , total_sum, stones ,dp);
      int nottake = solve(index - 1 , curr_sum , total_sum ,stones ,dp);
      
      return dp[index][curr_sum] = min(take,nottake);
    }


    int lastStoneWeightII(vector<int>& stones) {
        
        int n = stones.size();
        int index = n-1;

        int curr_sum = 0;
        int total_sum = accumulate(stones.begin(),stones.end(),0);
        
        vector<vector<int>>dp(n,vector<int>(total_sum+1,-1));

        return solve(index , curr_sum , total_sum ,stones,dp);

    }
};