class Solution {
public:
    bool canEat(vector<int>& piles, int k, int h){
        for(int i = 0; i < piles.size(); i++){
            int time = piles[i] % k == 0 ? piles[i] / k : piles[i]/ k + 1;
            h-= time;
            if(h < 0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end()), ans = -1;

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