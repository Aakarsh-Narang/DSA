class Solution {
public:
    vector<int> parent, size;

    void dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }

    int find(int a){
        if(parent[a] == a) return a;

        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return; // Already connected

        if(size[a] > size[b]){
            parent[b] = a;
            size[a] += size[b];
        }
        else{
            parent[b] = a;
            size[b] += size[a];
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        dsu(n);

        for(int i = 0; i < pairs.size(); i++){
            int a = pairs[i][0], b = pairs[i][1];

            if(find(a) == find(b)) continue;
            unite(a, b);
        }
        unordered_map<int, vector<char>> mp;    // all chars associated with certain component
        unordered_map<int, int> ptr; // curr value of vec pointer for each component

        for(int i = 0; i < n; i++){
            mp[find(i)].push_back(s[i]);
        }

        for(auto& [_, vec] : mp){
            sort(vec.begin(), vec.end());
        }

        for(int i = 0; i < n; i++){
            int component = find(i);
            int currChar = mp[component][ptr[component]];
            ptr[component]++;
            s[i] = currChar;
        }

        return s;
    }
};