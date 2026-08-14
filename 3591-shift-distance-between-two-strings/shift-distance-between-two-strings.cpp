class Solution {
public:
    long long findMinCost(int i, int j, vector<long long>& next, vector<long long>& prev, vector<int>& nextCost, vector<int>& prevCost) {
        long long cc, ccw;

        if (i <= j) {
            // forward (direct): i -> ... -> j
            cc = next[j] - next[i];

            // backward (wrap-around): i down to 0, jump to 25, down to j
            // prevCost[0] is the explicit jump from 'a' (0) to 'z' (25)
            ccw = prev[i] + prevCost[0] + (prev[25] - prev[j]);
        }
        else {
            // forward (wrap-around): i up to 25, jump to 0, up to j
            // nextCost[25] is the explicit jump from 'z' (25) to 'a' (0)
            cc = (next[25] - next[i]) + nextCost[25] + next[j];

            // backward (direct): i down to j
            ccw = prev[i] - prev[j];
        }

        return min(cc, ccw);
    }

    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        vector<long long> prev(26, 0), next(26, 0);
        long long cost = 0;

        // next[i] represents the cumulative cost to move forward from 'a' to i
        // next[0] stays 0.
        for(int i = 1; i < 26; i++){
            next[i] = next[i-1] + nextCost[i-1];
        }

        // prev[i] represents the cumulative cost to move backward from i down to 'a'
        // prev[0] stays 0.
        for(int i = 1; i < 26; i++){
            prev[i] = prev[i-1] + previousCost[i];
        }

        for(int k = 0; k < s.size(); k++){
            if(s[k] == t[k]) continue;

            int u = s[k] - 'a';
            int v = t[k] - 'a';

            cost += findMinCost(u, v, next, prev, nextCost, previousCost);
        }

        return cost;
    }
};