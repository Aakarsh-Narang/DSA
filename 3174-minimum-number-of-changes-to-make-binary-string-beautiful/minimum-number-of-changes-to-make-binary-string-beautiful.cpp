class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), changes = 0;
        
        for(int i = 1; i < n; i += 2){
            if(s[i] != s[i-1]){
                changes++;
            }
        } 

        return changes;
    }
};