class Solution {
public:
    bool wontCollide(int top, int curr){
        return (top < 0 && curr < 0) || (top > 0 && curr > 0) || (top < 0 && curr > 0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < asteroids.size(); i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            
            int top = st.top();
            int curr = asteroids[i];

            if(wontCollide(top, curr)) st.push(curr);

            else{
                bool survive = 1;
                while(!st.empty() && !wontCollide(st.top(), curr)){
                    if(abs(curr) < abs(st.top())) {
                        survive = 0; 
                        break;
                    }
                    if(abs(curr) == abs(st.top())){
                        survive = 0;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(survive) st.push(curr);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};