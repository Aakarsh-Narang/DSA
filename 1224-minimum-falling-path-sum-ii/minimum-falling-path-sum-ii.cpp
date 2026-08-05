class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n));

        int smallest = INT_MAX, smallest2 = INT_MAX, si;

        // Base case settlement
        for (int i = 0; i < n; i++) {
            dp[m-1][i] = matrix[m-1][i];
            if(matrix[m-1][i] < smallest){
                smallest2 = smallest;
                smallest = matrix[m-1][i];
                si = i;
            }
            else if(matrix[m-1][i] < smallest2){
                smallest2 = matrix[m-1][i];
            }
        }

        // Building up the DP table
        for(int i = m-2; i >= 0; i--){
            int currSmallest = INT_MAX, currSmallest2 = INT_MAX, currI;
            for(int j = 0; j < n; j++){
                if(j == si){
                    dp[i][j] = matrix[i][j] + smallest2;
                }
                else{
                    dp[i][j] = matrix[i][j] + smallest;
                }

                if(dp[i][j] < currSmallest){
                    currSmallest2 = currSmallest;
                    currSmallest = dp[i][j];
                    currI = j;  // Store smallest column for prev row
                }
                else if(dp[i][j] < currSmallest2){
                    currSmallest2 = dp[i][j];
                }
            }
            smallest = currSmallest;
            smallest2 = currSmallest2;
            si = currI;
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};