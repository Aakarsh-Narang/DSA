class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            bool tbp = 1;  // tbp -> to be pushed
            while(!st.empty()){
                bool currDir = asteroids[i] > 0;
                bool prevDir = st.top() > 0;
                int prev = st.top();
                int curr = asteroids[i];

                // Moiving Away  <-- -->
                if(currDir && !prevDir){
                    break;
                }
                // Moving in the same direction
                if(currDir == prevDir) break;
                if(abs(prev) > abs(curr)){
                    tbp = 0;
                    break;
                } 
                else if (abs(prev) < abs(curr)){ 
                    st.pop();
                }
                else{
                    tbp = 0;
                    st.pop();
                    break;
                }
            }
            if(tbp){
                st.push(asteroids[i]);
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