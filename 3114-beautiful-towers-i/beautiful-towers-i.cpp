class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        long long ans = 0;
        vector<long long> left(n, 0), right(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                left[i] = 1LL*(i+1)*heights[i];
            }
            else{
                left[i] = left[st.top()] + 1LL*(i-st.top())*heights[i];
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()){
                right[i] = 1LL*(n-i)*heights[i];
            }
            else{
                right[i] = right[st.top()] + 1LL*(st.top()-i)*heights[i];
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i] - heights[i]);
        }

        return ans;
    }
};