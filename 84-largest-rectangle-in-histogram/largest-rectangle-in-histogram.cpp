class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> left(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                int width = i - left[st.top()] - 1;
                ans = max(ans, height * width);
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()){
            int height = heights[st.top()];
            int width = n - left[st.top()] - 1;
            ans = max(ans, height * width);
            st.pop();
        }
    
        return ans;
    }
};