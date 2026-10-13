class Solution {
public:
    bool canEat(vector<int>& piles, int k, int h){
        for(int i = 0; i < piles.size(); i++){
            h -= (piles[i] / k) + ((piles[i] % k == 0) ? 0 : 1);
            if(h < 0) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), lo = 1, hi = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(lo <= hi){
            int mid = (hi - lo) / 2 + lo;
            if(canEat(piles, mid, h)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};