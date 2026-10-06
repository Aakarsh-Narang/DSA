class Solution {
public:
    bool isPalindrome(string s)
    {
        int l=0,r=s.size()-1;
        while(l<=r)
        {
            if(s[l++]==s[r--]);
            else
                return false;
        }
        return true;
    }
    void Backtrack(string s, vector<vector<string>>& ans, vector<string>& curr, int indx)
    {
        if(indx == s.size()){
            ans.push_back(curr);
        }

        for(int i = indx; i < s.size(); i++){
            if(isPalindrome(s.substr(indx, i - indx + 1))){
                curr.push_back(s.substr(indx, i - indx + 1));
                Backtrack(s, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;

        Backtrack(s, ans, curr, 0);
        
        return ans;
    }
};