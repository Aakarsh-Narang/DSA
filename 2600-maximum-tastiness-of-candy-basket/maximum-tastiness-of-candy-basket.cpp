class Solution {
public: 
    // Maximise the minimum Difference
    bool isPossible(vector<int>& price, int k, int tastiness){
        int candyCount = 1, prev = price[0];

        for(int i = 1; i < price.size(); i++){
            if(price[i] - prev >= tastiness){
                prev = price[i];
                candyCount++;
            }
        } 
        return candyCount >= k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size(), ans = 0, lo = 0, hi = price[n-1] - price[0];

        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(isPossible(price, k, mid)){
                ans = mid;
                lo = mid + 1;
            } 
            else hi = mid - 1;
        }

        return ans;
    }
};