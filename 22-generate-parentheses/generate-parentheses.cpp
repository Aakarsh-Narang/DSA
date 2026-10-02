class Solution {
public:
    void Helper(int open, int close, string curr, vector<string>& ans, int n){
        if((open==n && close==n)){
            ans.push_back(curr);
            return;
        }

        if(open<n) //We can either insert an ( or balance it by inserting ) if possible
            Helper(open+1,close,curr+"(",ans,n);

        if(close<open)
            Helper(open,close+1,curr+")",ans,n);

        
        
    }

    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        string curr="";

        Helper(0,0,curr,ans,n);

        return ans;
    }
};