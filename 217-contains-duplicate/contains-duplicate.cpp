class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(auto& n : nums){
            if(st.count(n)) return true;
            st.insert(n);
        }

        return false;
    }
};