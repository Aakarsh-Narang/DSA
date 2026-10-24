class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);

        for(auto& ch : s){
            freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i]) pq.push({freq[i], 'a'+i});
        }

        if(pq.top().first > (s.size()+1)/2) return "";
        string ans;

        while(!pq.empty()){
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            ans.push_back(ch1);

            if(!pq.empty()){
                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ans.push_back(ch2);

                if(cnt2 > 1) pq.push({cnt2-1, ch2});
            }
            if(cnt1 > 1) pq.push({cnt1-1, ch1});
        }

        return ans;
    }
};