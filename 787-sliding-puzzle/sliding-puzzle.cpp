class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Sort of Adj List for zero block at each board position
        vector<vector<int>> directions = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}};

        // Encrypt Board State as string
        string currState="";
        for(int i = 0; i<2; i++){
            for(int j = 0; j<3; j++){
                currState += to_string(board[i][j]);
            }
        }

        if(currState == "123450") 
            return 0;

        // Set to prevent duplicate visits 
        unordered_set<string> st;
        queue<string> q;
        q.push(currState);
        st.insert(currState);

        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                currState = q.front();
                if(currState == "123450") 
                        return moves;
                q.pop();
                int zeroIdx = currState.find('0');

                // All possible next States
                for(auto nextIdx:directions[zeroIdx]){
                    string nextState = currState;
                    swap(nextState[zeroIdx], nextState[nextIdx]);

                    
                    if(st.count(nextState)) continue;

                    q.push(nextState);
                    st.insert(nextState);
                }
            }
            moves++;
        }
        return -1;
    }
};