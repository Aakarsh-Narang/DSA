class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] >= currHeight) {
                int height = heights[st.top()];
                st.pop();

                int leftSmaller = st.empty() ? -1 : st.top();
                int width = i - leftSmaller - 1;

                ans = max(ans, height * width);
            }
            st.push(i);
        }

        return ans;
    }
};