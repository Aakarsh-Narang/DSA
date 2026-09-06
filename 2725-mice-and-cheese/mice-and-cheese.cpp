class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        // SINCE WE HAVE TO GIVE K CHEESE TO MOUSE 1 ANYWHO
        // WE FIRST ALL CHEESE TO MOUSE 2 & THEN SEE GIVING WHAT KINDS CAUSES MAX PROFIT OR LEAST LOSS
        // i.e. The ones with max profit or min loss
        // Calculate Rw1[i] - Rw2[i], for all, i E [0, n), 
        // In places where mouse 1 score is better or least worse than mouse 2 is given to mouse 1

        int n = reward1.size(), total = 0;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++){
            int diff = reward1[i] - reward2[i];
            pq.push({diff, i});
            total += reward2[i];
        }

        while(k--){
            auto [diff, indx] = pq.top();
            pq.pop();

            total += diff;
        }

        return total;
    }
};