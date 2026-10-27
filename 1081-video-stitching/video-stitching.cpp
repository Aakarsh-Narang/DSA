class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int i = 0, n = clips.size(), currEnd = 0, farthest = 0, cnt = 0;

        while(currEnd < time){
            while(i < n && clips[i][0] <= currEnd){
                farthest = max(farthest, clips[i][1]);
                i++;
            }

            if(farthest == currEnd) return -1;

            currEnd = farthest;
            cnt++;
        }

        return cnt;
    }
};