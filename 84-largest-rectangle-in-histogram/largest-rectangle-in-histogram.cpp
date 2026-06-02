class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int idx = st.top();
                st.pop();

                // Stack in monotonically increasing, so top would always be the boundary
                int left = st.empty() ? -1 : st.top();
                // Current elements kill the expansion of the prev cell, so it is it's right boundary
                int width = i - left - 1;

                ans = max(ans, heights[idx] * width);
            }
            st.push(i);
        }

        // Remaining elements in the stack
        while(!st.empty()){
            int idx = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = n - left - 1;
          
            ans = max(ans, heights[idx] * width);
        }
        
        return ans;
    }
};