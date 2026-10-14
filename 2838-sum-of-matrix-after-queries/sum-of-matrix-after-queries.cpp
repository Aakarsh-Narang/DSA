class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int> rowSeen(n, false), colSeen(n, false);

        reverse(queries.begin(), queries.end());

        long long sum = 0, rowCnt = 0, colCnt = 0;
        for(auto& q : queries){
            int type = q[0], indx = q[1], val = q[2];

            if(type == 0){
                if(!rowSeen[indx]){
                    rowCnt++;
                    sum += (n - colCnt) * val;
                    rowSeen[indx] = true;
                }
            }
            else{
                if(!colSeen[indx]){
                    colCnt++;
                    sum += (n - rowCnt) * val;
                    colSeen[indx] = true;
                }
            }
        }

        return sum;
    }
};