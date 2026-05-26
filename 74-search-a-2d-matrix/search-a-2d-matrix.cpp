class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo, hi, m = matrix.size(), n = matrix[0].size(), row=-1;
        lo = 0, hi = m-1;
        while(lo <= hi){
            int mid = (hi - lo)/2 + lo;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target){
                row = mid;
                break;
            }
            else if(matrix[mid][0] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        if(row == -1) return false;

        lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = (hi - lo)/2 + lo;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};