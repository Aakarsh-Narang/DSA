class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for(int d : digits) {
            count[d]++;
        }
        
        int ans = 0;
        
        // Step 1: Fix the units digit to an available even number
        for (int e = 0; e <= 8; e += 2) {
            if (count[e] == 0) continue;
            
            // "Borrow" this even digit for the units place
            count[e]--;
            
            // Step 2: Calculate remaining unique availabilities
            int u_nonzero = 0; // Unique non-zero digits available
            int u_total = 0;   // Total unique digits available (including 0)
            int d2 = 0;        // Non-zero digits with count >= 2
            
            for (int i = 0; i <= 9; i++) {
                if (count[i] > 0) {
                    u_total++;
                    if (i != 0) {
                        u_nonzero++;
                        if (count[i] >= 2) {
                            d2++;
                        }
                    }
                }
            }
            
            // Step 3: Apply the Rule of Product and Sum
            
            // Case A: Hundreds and Tens are different
            int diff_digits = u_nonzero * (u_total - 1);
            
            // Case B: Hundreds and Tens are the same
            int same_digits = d2;
            
            // Add combinations for this specific even ending
            ans += (diff_digits + same_digits);
            
            // Return the even digit to the pool for the next iteration
            count[e]++;
        }
        
        return ans;
    }
};