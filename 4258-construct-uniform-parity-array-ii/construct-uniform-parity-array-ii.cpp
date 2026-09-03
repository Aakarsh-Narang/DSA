class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = 1e9, smallestEven = 1e9;
        bool even = false, odd = false;
        for(auto& n : nums1){
            if(n % 2 != 0){ 
                smallestOdd = min(smallestOdd, n);
                odd = 1;
            }
            else{
                smallestEven = min(smallestEven, n);
                even = 1;
            }
        }
        if(!even || !odd) return true;

        if(smallestEven < smallestOdd) return false;

        return true;
    }
};