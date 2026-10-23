class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<tuple<int, char>> processes;  // {freq, Task}
        priority_queue<tuple<int, int, char>, vector<tuple<int, int, char>>, greater<tuple<int, int, char>>> cooldown; //{Time, freq, task}
        int time = 0;
        vector<int> freq(26, 0);

        for(auto& t : tasks){
            freq[t-'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0)
                processes.push({freq[i], i + 'A'});
        }

        while (!processes.empty() || !cooldown.empty()) {
            time++;

            while (!cooldown.empty() && time >= get<0>(cooldown.top())) {
                auto [readyTime, f, t] = cooldown.top();
                cooldown.pop();
                processes.push({f, t});
            }

            if (!processes.empty()) {
                auto [f, task] = processes.top();
                processes.pop();

                if (f > 1)
                    cooldown.push({time + n + 1, f - 1, task});
            }
        }

        return time;
    }
};