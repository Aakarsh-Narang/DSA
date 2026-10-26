class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> avail;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> occupied;
        int m = tasks.size(), n = servers.size(); 
        vector<int> ans(m);

        for(int i = 0; i < n; i++){
            avail.push({servers[i], i});
        }
        long long time = 0;
        for(int i = 0; i < m; i++){
            time = max(time, 1LL*i);
            int dur = tasks[i];
            if(avail.empty()){
                auto [endTime, wt, indx] = occupied.top();
                time = endTime;
            }
            while(!occupied.empty() && time >= get<0>(occupied.top())){
                auto [endTime, wt, indx] = occupied.top();
                occupied.pop();

                avail.push({wt, indx});
            }

            auto [wt, indx] = avail.top();
            avail.pop();

            ans[i] = indx;
            occupied.push({time + dur, wt, indx});
        }

        return ans;
    }
};