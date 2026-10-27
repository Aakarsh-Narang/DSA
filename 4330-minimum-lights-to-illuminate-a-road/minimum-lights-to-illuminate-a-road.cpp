class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n+1, 0);

        for(int i = 0; i < n; i++){
            if(lights[i]){
                int prev = max(0, i - lights[i]);
                int next = min(n, i + lights[i]+1);
                diff[prev] += 1;
                diff[next] -= 1;
            }
        }

        int runningSum = 0, ans = 0;

        for(int i = 0; i < n; i++){
            runningSum += diff[i];

            if(!runningSum){
                ans++;
                runningSum++;
                int next = min(n, i+3);
                diff[next] -= 1;  // Turns off after illuminating 3 blocks
            }
        }

        return ans;
    }
};