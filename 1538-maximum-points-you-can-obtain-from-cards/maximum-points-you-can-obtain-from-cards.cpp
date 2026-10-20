class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), curr = 0, minSum = INT_MAX;
        int l = 0, r = 0;

        while(r < (n-k)){
            curr += cardPoints[r];
            r++;
        }
        minSum = min(minSum, curr);

        while(r < n){
            curr -= cardPoints[l];
            curr += cardPoints[r];
            minSum = min(minSum, curr);
            l++;
            r++;
        }

        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        return totalSum - minSum;
    }
};