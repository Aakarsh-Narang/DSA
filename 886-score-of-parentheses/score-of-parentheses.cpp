class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int curr = 0;

        for(char ch : s) {
            if(ch == '(') {
                // Entering a new level/ shell
                st.push(curr);
                curr = 0;
            }
            else {
                int prev = st.top();
                st.pop();

                // () -> 1 Empty Shell
                if(curr == 0)
                    curr = 1;
                // (A) -> 2 * A  Nested Shell
                else
                    curr = 2 * curr;

                curr += prev;
            }
        }

        return curr;
    }
};