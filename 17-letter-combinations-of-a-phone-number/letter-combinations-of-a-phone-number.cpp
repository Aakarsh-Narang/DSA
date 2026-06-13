class Solution {
public:
    void Backtrack(vector<vector<char>>& alphabets, vector<string>& ans, string curr, string digits, int idx){
        int n = digits.size();
        if(idx == n){
            ans.push_back(curr);
            return;
        }
        int currNo = digits[idx] - '0';
        vector<char> options = alphabets[currNo];

        for(int i = 0; i < options.size(); i++){
            curr += options[i];

            Backtrack(alphabets, ans, curr, digits, idx+1);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> alphabets={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'}, {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

        int k=digits.size();
        vector<string> ans;
        string curr="";

        if(digits.size()==0)
            return ans;

        Backtrack(alphabets,ans,curr,digits,0);

        return ans;
    }
};