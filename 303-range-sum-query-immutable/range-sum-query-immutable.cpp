class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int sum = 0;
        prefix.push_back(0);
        for(auto& n : nums){
            sum += n;
            prefix.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */