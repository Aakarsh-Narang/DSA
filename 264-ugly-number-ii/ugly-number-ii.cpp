class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> ugly;
        ugly.insert(1);

        auto it = ugly.begin();

        for(int i = 0; i < n - 1; i++) {
            long long curr = *it;

            ugly.insert(curr * 2);
            ugly.insert(curr * 3);
            ugly.insert(curr * 5);

            it++;
        }

        return *it;
    }
};