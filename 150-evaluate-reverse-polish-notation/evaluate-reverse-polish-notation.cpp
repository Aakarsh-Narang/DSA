class Solution {
public:
    int solve(int a, int b, string op){
        int ans;
        if(op == "+") ans = a+b;
        else if(op == "-") ans = a - b;
        else if(op == "*") ans = a * b;
        else ans = a / b;

        return ans; 
    }
    bool isOp(string s){
        return (s == "+") || (s == "-") || (s == "*") || (s == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            string curr = tokens[i];
            if(isOp(curr)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                st.push(solve(a, b, curr));
            }
            else{
                st.push(stoi(curr));
            }
        }

        return st.top();
    }
};