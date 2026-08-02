class Solution {
public:
    int solve(int index , int currSum , int & totalSum , vector<int>&stones , vector<vector<int>>&dp)
    {
      if(index < 0)
        return abs(totalSum - 2 * currSum);
      
      if(dp[index][currSum] != -1)
        return dp[index][currSum];

      int take = solve(index - 1 , currSum + stones[index] , totalSum, stones ,dp);
      int notTake = solve(index - 1 , currSum , totalSum ,stones ,dp);
      
      return dp[index][currSum] = min(take, notTake);
    }


    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int index = n-1;

        int currSum = 0;
        int totalSum = accumulate(stones.begin(),stones.end(),0);
        
        vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));

        return solve(index , currSum , totalSum ,stones, dp);

    }
};