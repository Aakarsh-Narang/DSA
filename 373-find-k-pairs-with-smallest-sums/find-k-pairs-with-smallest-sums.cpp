class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;

        // sum, row, col
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        set<pair<int, int>> st;

        for(int i = 0; i < n1; i++){
            pq.push({nums1[i] + nums2[0], i, 0});
            st.insert({i, 0});
        }

        // for(int i = 1; i < n2; i++){
        //     pq.push({nums1[0] + nums2[i], 0, i});
        //     st.insert({0, i});
        // }

        while(k--){
            auto [sum, r, c] = pq.top();
            pq.pop();

            if(r + 1 < n1 && st.count({r + 1, c}) == 0){
                pq.push({nums1[r + 1] + nums2[c], r + 1, c});
                st.insert({r + 1, c});
            }
            if(c + 1 < n2 && st.count({r, c + 1}) == 0){
                pq.push({nums1[r] + nums2[c + 1], r, c + 1});
                st.insert({r, c + 1});
            }

            ans.push_back({nums1[r], nums2[c]});
        }

        return ans;
    }
};