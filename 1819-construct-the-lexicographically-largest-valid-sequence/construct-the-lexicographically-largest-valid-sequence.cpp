class Solution {
public:
    bool solve(int& n, vector<int>& ans, vector<bool>& used, int indx){
        if(indx == 2*n-1) return true;

        if(ans[indx] != 0) return solve(n, ans, used, indx+1);

        for(int i = n; i > 0 ; i--){
            if(used[i]) continue;
            if(i == 1){
                ans[indx] = 1;
                used[1] = true;

                if(solve(n, ans, used, indx+1)) return true;

                ans[indx] = 0;
                used[1] = false;
            }
            else{
                if(i+indx < 2*n-1 && ans[i+indx] == 0){
                    ans[indx] = i;
                    ans[i+indx] = i;
                    used[i] = 1;

                    if(solve(n, ans, used, indx+1)) return true;

                    ans[indx] = 0;
                    ans[i+indx] = 0;
                    used[i] = false;
                }
            }
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2 * n - 1, 0); // 0 means empty
        vector<bool> used(n + 1, false);

        solve(n, ans, used, 0);

        return ans;
    }
};