class Solution {
public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
                return a.second > b.second;

            return a.first > b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;  

        for(int i=0; i<arr.size(); i++){
            pq.push({abs(arr[i] - x), arr[i]});
        }
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }        
        sort(ans.begin(), ans.end());
        return ans;
    }
};