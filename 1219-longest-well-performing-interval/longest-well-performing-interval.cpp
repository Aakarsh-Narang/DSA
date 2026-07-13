class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), ans = 0;
        unordered_map<int, int> mp;
        vector<int> prefix(n, 0);

        hours[0] = hours[0] >8 ? 1 : -1;
        prefix[0] = hours[0];

        for(int i = 1; i < n; i++){
            if(hours[i] > 8){ 
                ans = 1;
                hours[i] = 1;
            }
            else hours[i] = -1;
            prefix[i] = hours[i] + prefix[i-1];
        }

        for(int i = 0; i < n; i++){
            if (prefix[i] > 0)
                ans = max(ans, i + 1);
            else if (mp.count(prefix[i] - 1))
                ans = max(ans, i - mp[prefix[i] - 1]);
            else{
                if(!mp.count(prefix[i]))
                    mp[prefix[i]] = i;
            }
        }

        return ans;
    }
};