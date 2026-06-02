class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur, vector<int>& waterStart, vector<int>& waterDur) {
        
        int landCount = landStart.size();
        int waterCount = waterStart.size();
        int earliestEnd = INT_MAX;

        // Try all land first → water second combinations
        for (int landIdx = 0; landIdx < landCount; ++landIdx) {
            int landEnd = landStart[landIdx] + landDur[landIdx];
            for (int waterIdx = 0; waterIdx < waterCount; ++waterIdx) {
                int combinedEnd = max(landEnd, waterStart[waterIdx]) + waterDur[waterIdx];
                earliestEnd = min(earliestEnd, combinedEnd);
            }
        }

        // Try all water first → land second combinations
        for (int waterIdx = 0; waterIdx < waterCount; ++waterIdx) {
            int waterEnd = waterStart[waterIdx] + waterDur[waterIdx];
            for (int landIdx = 0; landIdx < landCount; ++landIdx) {
                int combinedEnd = max(waterEnd, landStart[landIdx]) + landDur[landIdx];
                earliestEnd = min(earliestEnd, combinedEnd);
            }
        }

        return earliestEnd;
    }
};
