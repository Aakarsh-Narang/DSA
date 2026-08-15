class Solution {
public:
    string merge(string a, string b) {
        // If b is already inside a, no need to add anything
        if (a.find(b) != string::npos)
            return a;

        // If a is already inside b
        if (b.find(a) != string::npos)
            return b;

        int overlap = 0;

        // Maximum suffix of a == prefix of b
        for (int len = 1; len <= min(a.size(), b.size()); len++) {
            if (a.substr(a.size() - len) == b.substr(0, len))
                overlap = len;
        }

        return a + b.substr(overlap);
    }

    string minimumString(string a, string b, string c) {
        vector<string> v = {a, b, c};
        string ans = "";

        sort(v.begin(), v.end());

        do {
            string cur = merge(v[0], v[1]);
            cur = merge(cur, v[2]);

            if (ans == "" ||
                cur.size() < ans.size() ||
                (cur.size() == ans.size() && cur < ans)) {
                ans = cur;
            }

        } while (next_permutation(v.begin(), v.end()));

        return ans;
    }
};