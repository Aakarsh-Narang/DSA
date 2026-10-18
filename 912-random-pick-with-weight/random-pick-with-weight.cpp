class Solution {
public:
    int total = 0;
    vector<int> prefix;
    Solution(vector<int>& w) {
        for(auto& num : w){
            total += num;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        return lower_bound(prefix.begin(), prefix.end(), (rand() % total) +1) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */