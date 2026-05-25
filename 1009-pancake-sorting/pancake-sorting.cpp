class Solution {
public:
    void printArr(vector<int>& arr){
        for(auto&  e: arr)
            cout<<e << " ";
        cout<<endl;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int target = n-i;
            int ff;  // First-Flip
            for(int j = 0; j < n; j++){
                if(arr[j] == target){
                    ff = j;
                    break;
                }
            }
            if(ff == target-1 ) continue;

            ans.push_back(ff+1);
            ans.push_back(target);

            if(ff != 0)
                reverse(arr.begin(), arr.begin() + ff+1);
            // printArr(arr);
            
            if(target != 1)
                reverse(arr.begin(), arr.begin() + target);
            // printArr(arr);
        }
        return ans;
    }
};