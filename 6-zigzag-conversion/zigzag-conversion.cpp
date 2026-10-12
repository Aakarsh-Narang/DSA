class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string ans = "";
        int i = 0, r = 0, c = 0, n = s.length();
        vector<vector<char>> diag(numRows, vector<char>(n, ' '));

        while(i < n){
            if(r < numRows){
                diag[r++][c] = s[i++];
            }
            else{
                r-=2;  // Bring back from n -> n-2
                c++;
                while(r > 0 && i < n) diag[r--][c++] = s[i++];

            }
        }

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j++){
                if(diag[i][j] == ' ') continue;
                ans += diag[i][j];
            }
        }

        return ans;
    }
};