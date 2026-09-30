class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;

        // sum, row, col
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        for(int i = 0; i < n1; i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }


        while(k--){
            auto [sum, r, c] = pq.top();
            pq.pop();

            if(c + 1 < n2){
                pq.push({nums1[r] + nums2[c + 1], r, c + 1});
            }

            ans.push_back({nums1[r], nums2[c]});
        }

        return ans;
    }
};