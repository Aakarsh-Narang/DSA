class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto& s : stones) pq.push(s);

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            if(x == y) continue;
            pq.push(y - x);
        }

        pq.push(0);
        return pq.top();
    }
};