class Solution {
public:
    void backtrack(string& num, int target, int pos, long long total, long long last, string expr, vector<string>& ans) {
        if (pos == num.size()) {
            if (total == target)
                ans.push_back(expr);
            return;
        }

        for (int end = pos; end < num.size(); end++) {
            // Prevent numbers like 05, 012, etc.
            if (num[pos] == '0' && end != pos)
                break;

            string part = num.substr(pos, end - pos + 1);
            long long val = stoll(part);

            // First number
            if (pos == 0) {
                backtrack(num, target, end + 1, val, val, part, ans);
            }
            else {
                // Addition
                backtrack(num, target, end + 1, total + val, val, expr + "+" + part, ans);

                // Subtraction
                backtrack(num, target, end + 1, total - val, -val, expr + "-" + part, ans);

                // Multiplication
                backtrack(num, target, end + 1, total - last + (last * val), last * val, expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};