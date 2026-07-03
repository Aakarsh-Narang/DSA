class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks){
        int n = tasks.size();
        vector<int> ans;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> occupied;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> avail;

        for(int i = 0; i < servers.size(); ++i){
            avail.push({servers[i], i});  // {ServerVal, Idx}
        }

        for(int i = 0; i < n; ++i){
            while(!occupied.empty() && get<0>(occupied.top()) <= i){
                auto [currTime, currServer, serverIdx] = occupied.top();
                occupied.pop();
                avail.push({currServer, serverIdx});
            }
            int currServer, serverIdx, freeTime;
            if(avail.empty()){
                tie(freeTime, currServer, serverIdx) = occupied.top();
                occupied.pop();
            }
            else{
                tie(currServer, serverIdx) = avail.top();
                avail.pop();
                freeTime = i;
            }
            ans.push_back(serverIdx);

            occupied.push({1LL*freeTime + tasks[i], currServer, serverIdx});
        }

        return ans;
    }
};