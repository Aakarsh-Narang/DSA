class Solution {
public:
    vector<int> parent, size;

    void dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n);
    }

    int find(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return;  // Already in same component

        if(size[rootA] < size[rootB]){
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else{
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        const int OFFSET = 10001;
        dsu(20002);

        unordered_set<int> nodes;

        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;  // As row & col numbers may overlap

            unite(row, col);

            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;
        for(auto& n : nodes){
            if(parent[n] == n) components++;
        }

        return stones.size() - components;
    }
};