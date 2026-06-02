class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        stack<int> st;
        st.push(asteroids[0]);
        for(int i = 1; i < n; i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            bool tbp = true;  // tbp - to be pushed
            while(!st.empty()){
                bool currDir = asteroids[i] < 0;
                bool prevDir = st.top() < 0;
                bool collide = currDir != prevDir;

                //  <--  -->  Moving away
                if(prevDir && !currDir) break;  
                if(collide){
                    if(abs(asteroids[i]) > abs(st.top())){
                        st.pop();
                    }
                    else if(abs(asteroids[i]) == abs(st.top())){
                        st.pop();
                        tbp = false;
                        break;
                    }
                    else{
                        tbp = false;
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(tbp) st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};