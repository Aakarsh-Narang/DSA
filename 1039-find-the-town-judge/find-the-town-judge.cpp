class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> st;
        unordered_map<int, int> mp;
        
        for(int i = 1; i <= n; i++) st.insert(i);

        for(auto& t : trust){
            int a = t[0], b = t[1];
            if(st.count(a)) st.erase(a);
            mp[b]++;
        }

        if(!st.size()) return -1;
        
        int judge = *st.begin();

        if(mp[judge] == n-1) return judge;
        return -1;
    }
};