class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return {nums[0]};
        
        int cnt1 = 0, cnt2 = 0, candidate1 = 0, candidate2 = 0, n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1){
                cnt1++;
            }
            else if(nums[i] == candidate2){
                cnt2++;
            }
            else if(cnt1 == 0){
                candidate1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                candidate2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }   

        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1){
                cnt1++;
            }
            else if(nums[i] == candidate2){
                cnt2++;
            }
        }

        // cout << candidate1 <<" "<< candidate2;

        if(cnt1 > n/3) ans.push_back(candidate1);
        if(cnt2 > n/3) ans.push_back(candidate2);

        return ans;
    }
};