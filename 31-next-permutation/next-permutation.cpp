class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Iterate from right to left
        // Find first pair where nums[i] < nums[i+1]
        // Find first largest element tha nums[i] to the right
        // Swap nums[i] with just larger element
        // Reverse remaining array after i

        stack<int> st;
        int n = nums.size();
        int indx = -1;

        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                indx = i;
                break;
            }
        }

        if(indx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i > indx; i--){
            if(nums[i] > nums[indx]){
                swap(nums[i], nums[indx]);
                break;
            }
        }

        reverse(nums.begin() + indx + 1, nums.end());
    }
};