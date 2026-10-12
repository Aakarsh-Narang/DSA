class Solution {
public:
    bool solve(int n, vector<int>& ans, vector<bool>& used, int indx) {
        if (indx == 2 * n - 1) return true;

        // If the current spot is already filled by a previous pair, skip to the next
        if (ans[indx] != 0) {
            return solve(n, ans, used, indx + 1);
        }

        // Try placing the largest numbers first to guarantee lexicographically largest
        for (int i = n; i > 0; i--) {
            if (used[i]) continue;

            // Handle 1 separately since it only appears once
            if (i == 1) {
                ans[indx] = 1;
                used[1] = true;
                
                if (solve(n, ans, used, indx + 1)) return true;
                
                ans[indx] = 0;
                used[1] = false;
            } 
            // For numbers > 1, place BOTH occurrences at the same time
            else {
                // Check if the second spot is within bounds AND empty
                if (indx + i < 2 * n - 1 && ans[indx + i] == 0) {
                    ans[indx] = i;
                    ans[indx + i] = i; // Place the second occurrence
                    used[i] = true;
                    
                    if (solve(n, ans, used, indx + 1)) return true;
                    
                    // Backtrack both spots
                    ans[indx] = 0;
                    ans[indx + i] = 0;
                    used[i] = false;
                }
            }
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0); // 0 means empty
        vector<bool> used(n + 1, false);

        solve(n, ans, used, 0);

        return ans;
    }
};