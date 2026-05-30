class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> st;
        vector<int> ans;
        for(auto& num : digits){
            st.push(num);
        }

        int carry = 1;
        while(!st.empty()){
            int num = st.top() + carry;
            st.pop();
            carry = num / 10;
            ans.push_back(num % 10);
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};