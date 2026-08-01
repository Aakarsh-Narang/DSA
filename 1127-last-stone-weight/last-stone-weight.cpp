class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto& s : stones){
            pq.push(s);
        }

        while(true){
            if(pq.size() == 1) return pq.top();
            if(pq.size() == 0) return 0;

            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y) continue;
            else pq.push(y-x);
        }
        return 0;
    }
};