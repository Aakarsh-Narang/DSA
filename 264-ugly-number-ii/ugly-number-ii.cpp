class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly;
        unordered_set<long long> st;

        ugly.push_back(1);
        st.insert(1);

        int generator = 0;

        while(generator < n - 1) {
            long long curr = ugly[generator];

            if(!st.count(curr * 2)) {
                ugly.push_back(curr * 2);
                st.insert(curr * 2);
            }

            if(!st.count(curr * 3)) {
                ugly.push_back(curr * 3);
                st.insert(curr * 3);
            }

            if(!st.count(curr * 5)) {
                ugly.push_back(curr * 5);
                st.insert(curr * 5);
            }

            generator++;

            sort(ugly.begin() + generator, ugly.end());
        }

        return ugly[n - 1];
    }
};