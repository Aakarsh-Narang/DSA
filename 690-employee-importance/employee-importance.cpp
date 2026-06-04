/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*>& mp){
        int ans = mp[id]->importance;
        vector<int> subTree = mp[id]->subordinates;

        for(auto& sub: subTree){
            ans += dfs(sub, mp);
        }

        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;   // id->Address

        for(auto& E : employees){
            mp[E->id] = E;
        }

        int ans = dfs(id, mp);

        return ans;
    }
};