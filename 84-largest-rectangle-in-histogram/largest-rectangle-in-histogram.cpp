class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> pre(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int idx = st.top();
                st.pop();

                int width = i - pre[idx] - 1;
                int area = heights[idx] * width;
                ans = max(ans, area);
            }
            if(st.empty()) pre[i] = -1;
            else pre[i] = st.top();

            st.push(i);
        }

        // Remaining elements in the stack
        while(!st.empty()){
            int idx = st.top();
            st.pop();

            int width = n - pre[idx] - 1;
            int area = heights[idx] * width;
            ans = max(ans, area);
        }
        
        return ans;
    }
};