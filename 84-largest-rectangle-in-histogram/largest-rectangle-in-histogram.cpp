class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int idx = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                int area = heights[idx] * width;
                ans = max(ans, area);
            }
            st.push(i);
        }

        // Remaining elements in the stack
        while(!st.empty()){
            int idx = st.top();
            st.pop();

            int left = st.empty() ? -1 : st.top();
            int width = n - left - 1;
            int area = heights[idx] * width;
            ans = max(ans, area);
        }
        
        return ans;
    }
};