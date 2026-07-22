class Solution {
public:
    vector<int> parent, size;

    void dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find(int a) {
        if (parent[a] == a)
            return a;

        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] > size[b]) {
            parent[b] = a;
            size[a] += size[b];
        } else {
            parent[a] = b;
            size[b] += size[a];
        }
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        dsu(n);
        vector<bool> ans;

        for (auto& req : requests) {
            int a = req[0], b = req[1];

            bool flg = true;
            for (auto& res : restrictions) {
                int x = res[0], y = res[1];
                if ((find(a) == find(x) && find(b) == find(y)) ||
                    ((find(a) == find(y) && find(b) == find(x)))) {
                    ans.push_back(false);
                    flg = 0;
                    break;
                }
            }
            if (flg) {
                ans.push_back(true);
                unite(a, b);
            }
        }

        return ans;
    }
};