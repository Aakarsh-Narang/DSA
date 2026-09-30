class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i = n-1; i >=0; i--){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] -1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }

        return ans;
    }
};