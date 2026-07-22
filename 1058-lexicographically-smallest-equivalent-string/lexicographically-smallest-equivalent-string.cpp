class Solution {
public:
    vector<char> parent;

    void dsu() {
        parent.resize(26);
        iota(parent.begin(), parent.end(), 'a');
    }

    char find(char c) {
        if (parent[c - 'a'] == c)
            return c;

        return parent[c - 'a'] = find(parent[c - 'a']);
    }

    void unite(char a, char b) {
        char rootA = find(a);
        char rootB = find(b);

        if (rootA == rootB)
            return;

        if (rootA < rootB)
            parent[rootB - 'a'] = rootA;
        else
            parent[rootA - 'a'] = rootB;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu();

        for (int i = 0; i < s1.size(); i++)
            unite(s1[i], s2[i]);

        for (int i = 0; i < baseStr.size(); i++){
            baseStr[i] = find(baseStr[i]);
        }

        return baseStr;
    }
};