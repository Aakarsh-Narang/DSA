class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0, i = 1;

        while(i < arr.size() && arr[i] > arr[i-1]){
            ans = i;
            i++;
        }
        return ans;
    }
};