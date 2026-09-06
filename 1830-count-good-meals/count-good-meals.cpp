class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPairs(vector<int>& deliciousness) {
        sort(deliciousness.begin(), deliciousness.end());
        int maxNum = *max_element(deliciousness.begin(), deliciousness.end());

        int currTarget = 1, ans = 0, n = deliciousness.size();
        while(currTarget <= 2*maxNum){
            int l = 0, r = n-1;
            while(l < r){
                if(deliciousness[l] + deliciousness[r] == currTarget){
                    int leftVal = deliciousness[l];
                    int rightVal = deliciousness[r];

                    int cnt1 = 0, cnt2 = 0;

                    while(l <= r && deliciousness[l] == leftVal){
                        l++;
                        cnt1++;
                    }

                    while(r >= l && deliciousness[r] == rightVal){
                        r--;
                        cnt2++;
                    }

                    if(leftVal == rightVal)
                        ans = (ans + 1LL * cnt1 * (cnt1 - 1) / 2) % MOD;
                    else
                        ans = (ans + 1LL * cnt1 * cnt2) % MOD;
                }
                else if(deliciousness[l] + deliciousness[r] > currTarget){
                    r--;
                }
                else{
                    l++;
                }
            }
            currTarget = currTarget << 1;
        }
        
        return ans;
    }
};