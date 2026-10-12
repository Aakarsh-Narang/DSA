class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string ans = "";
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        // Iterate through each row one by one
        for (int i = 0; i < numRows; i++) {
            // Jump by cycleLen to process the current row
            for (int j = 0; j + i < n; j += cycleLen) {
                // 1. Add the vertical character (always exists for the row)
                ans += s[j + i];

                // 2. Add the diagonal character (only for inner rows)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    ans += s[j + cycleLen - i];
                }
            }
        }

        return ans;
    }
};