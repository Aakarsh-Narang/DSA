class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser, greater;
        int n = nums.size(), equalCnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                lesser.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                equalCnt++;
            }
            else{
                greater.push_back(nums[i]);
            }
        }

        while(equalCnt){
            lesser.push_back(pivot);
            equalCnt--;
        }
        lesser.insert(lesser.end(), greater.begin(), greater.end());

        return lesser;
    }
};