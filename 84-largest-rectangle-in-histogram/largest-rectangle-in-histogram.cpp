class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> pre(n), post(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                post[st.top()] = i;
                st.pop();
            }
            if(st.empty()) pre[i] = -1;
            else pre[i] = st.top();

            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int width = post[i] - pre[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        
        return ans;
    }
};