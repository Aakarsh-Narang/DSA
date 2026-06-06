class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0, leftMax = 0, rightMax = 0, left = 0, right = n-1;

        while(left < right){
            if(height[left] <= height[right]){
                ans += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);

                left++;
            }
            else{
                ans += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                
                right--;
            }
        }

        return ans;
    }
};