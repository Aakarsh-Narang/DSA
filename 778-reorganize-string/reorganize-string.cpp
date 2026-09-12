class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
        for(auto& ch:s) freq[ch - 'a']++;
        for(int i=0; i<26; i++){
            if(!freq[i]) continue;
            pq.push({freq[i], 'a'+i});
        }
        
        int cnt = pq.top().first;
        if(cnt > ((n+1)/2)) return "";
        string ans(n, '-');
        int indx = 0;

        // Interleaving insertion
        while(!pq.empty()){
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            ans[indx++] = ch1;

            if(!pq.empty()){
                auto [cnt2, ch2] = pq.top();
                pq.pop();
                ans[indx++] = ch2;

                cnt2--;
                if(cnt2) pq.push({cnt2, ch2}); 
            }
            cnt1--;
            if(cnt1) pq.push({cnt1, ch1}); 
        }
        return ans;
    }
};