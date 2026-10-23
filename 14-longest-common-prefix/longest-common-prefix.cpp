class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string a = strs[0], b = strs.back();

        int len = 0, n = min(a.size(), b.size());
        string ans = "";
        while(len < n && a[len] == b[len]){
            ans += a[len];
            len++;
        }

        return ans;
    }
};