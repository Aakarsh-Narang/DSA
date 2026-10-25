class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights){
        int n = maxHeights.size();
        long long ans = 0;
        vector<long long> left(n), right(n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i]) st.pop();

            if(st.empty()){
                left[i] = 1LL * (i+1) * maxHeights[i];
            }
            else{
                left[i] = left[st.top()] + 1LL * (i - st.top()) * maxHeights[i];
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i]) st.pop();

            if(st.empty()){
                right[i] = 1LL * (n-i) * maxHeights[i];
            }
            else{
                right[i] = right[st.top()] + 1LL * (st.top() - i) * maxHeights[i];
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
        }

        return ans;
    }
};