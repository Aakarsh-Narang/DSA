class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, currMax = 0, n = height.size();
        vector<int> right(n, 0);

        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        for(int i = 0; i < n; i++){
            currMax= max(currMax, height[i]);
            ans += min(currMax, right[i]) - height[i];
        }

        return ans;
    }
};