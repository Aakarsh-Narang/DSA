class Solution {
public:
    vector<char> parent;
    vector<int> size;

    void dsu(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 'a');
        size.resize(n, 1);
    }

    char find(char a){
        if(parent[a - 'a'] == a) return a;

        return parent[a-'a'] = find(parent[a-'a']);
    }

    void unite(char a, char b){
        char rootA = find(a);
        char rootB = find(b);

        if(rootA == rootB) return;

        if(size[rootA -'a'] > size[rootB-'a']){
            parent[rootB-'a'] = rootA;
            size[rootA-'a'] += size[rootB-'a'];
        }    
        else{
            parent[rootA-'a'] = rootB;
            size[rootB-'a'] += size[rootA-'a'];
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        dsu(26);

        for(int i = 0; i < n; i++){
            unite(s1[i], s2[i]);
        }

        unordered_map<char, char> mp;
        
        // mark smallest chars for ultimate parents of each componet
        for(char c='a'; c<='z'; c++){
            char root = find(c);

            if(!mp.count(root))
                mp[root] = c;
            else
                mp[root] = min(mp[root], c);
        }

        for(int i = 0; i < baseStr.size(); i++){
            baseStr[i] = mp[find(baseStr[i])];
        }

        return baseStr;
    }
};