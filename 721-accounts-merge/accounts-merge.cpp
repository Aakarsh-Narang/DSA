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
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB) return;

        if(size[rootA] > size[rootB]){
            parent[rootB] = rootA;
            size[rootA] += size[rootB]; 
        }
        else{
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu(n);
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.count(accounts[i][j])){
                    unite(i, mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> merged;

        for (auto &[email, account] : mp) {
            int root = find(account);
            merged[root].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto& [indx, mails] : merged){
            sort(mails.begin(), mails.end());
            vector<string> temp;
            temp.push_back(accounts[indx][0]);
            temp.insert(temp.begin() + 1, mails.begin(), mails.end());
            ans.push_back(temp);
        }

        return ans;
    }
};