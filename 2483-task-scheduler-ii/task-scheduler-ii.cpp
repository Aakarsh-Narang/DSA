class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long days=0;

        for(int i = 0; i < tasks.size(); i++){
            if(mp.count(tasks[i])  &&  days - mp[tasks[i]]  <= space){
                days+=(space-(days - mp[tasks[i]])+1);
            }
            else{
                days++;   
            }
            mp[tasks[i]]=days;
            
        }

        return days;
    }
};