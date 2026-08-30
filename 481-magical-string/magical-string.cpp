class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        string s = "122";

        int i = 2;       // points to the group length
        int num = 1;     // character to generate next
        int ones = 1;    // '1' in "122"

        while (s.size() < n) {
            int len = s[i] - '0';

            for (int j = 0; j < len && s.size() < n; j++) {
                s += char('0' + num);

                if (num == 1)
                    ones++;
            }

            num = 3 - num;  // 1 -> 2, 2 -> 1
            i++;
        }

        return ones;
    }
};