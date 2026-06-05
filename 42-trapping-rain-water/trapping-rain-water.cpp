class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev(n, 0);

        int maxi = 0;
        for(int i = 0; i < n; i++){
            prev[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        int ans = 0;
        maxi = 0;
        for(int i = n-1; i>= 0; i--){
            ans += max(0, min(prev[i], maxi) - height[i]);
            maxi = max(maxi, height[i]);
        }

        return ans;
    }
};