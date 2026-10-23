class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<char> st;
        int n = seq.size();
        vector<int> ans;
        
        for(auto& ch : seq){
            if(ch == ')') st.pop();
            ans.push_back(st.size()%2);
            if(ch == '('){
                st.push(ch);
            }
        }

        return ans;
    }
};