class RandomizedSet {
public:
    
    unordered_map<int, int> mp;  // val -> index in array
    vector<int> nums;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            nums.push_back(val);
            mp[val] = nums.size()-1;

            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int idx = mp[val];
            int last = nums.size()-1;

            mp[nums[last]] = idx;
            nums[idx] = nums[last];

            mp.erase(val);
            nums.pop_back();

            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = nums.size();

        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */