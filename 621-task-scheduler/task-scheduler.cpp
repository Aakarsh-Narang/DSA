class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> left;
        queue<pair<int, int>> cooldown;  // Count, Time for next execution
        vector<int> freq(26, 0);

        for(auto& ch: tasks) freq[ch-'A']++;
        for(int i=0; i<26; i++)
            if(freq[i]>0)
                left.push(freq[i]);
        
        int time = 0;
        
        while(!cooldown.empty() || !left.empty()){
            time++;
            if(!cooldown.empty() && cooldown.front().second <= time){
                auto [cnt, time] = cooldown.front();
                cooldown.pop();
                left.push(cnt);
            }
            if(!left.empty()){
                int cnt = left.top();
                left.pop();
                if(cnt > 1) cooldown.push({cnt-1, time + n + 1});
            }
        }

        return time;
    }
};