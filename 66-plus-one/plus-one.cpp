class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            int num = digits[i] + carry;
            carry = num / 10;
            digits[i] = num % 10;
        }

        if(!carry) return digits;

        vector<int> ans;
        ans.push_back(carry);
        ans.insert(ans.end(), digits.begin(), digits.end());
        
        return ans;
    }
};