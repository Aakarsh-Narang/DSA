class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> prefix(n, 0), ans(n);

        if(k == 0) return prefix;

        prefix[0] = code[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + code[i];
        }
        if(k > 0){
            for(int i = 0; i < n; i++){
                if(i+k < n){
                    ans[i] = prefix[i+k] - prefix[i];
                }
                else{
                    ans[i] = prefix[n-1] - prefix[i] + prefix[(i+k) % n];
                }
            }
        }
        if(k < 0){
            k = -k;

            for(int i = 0; i < n; i++){
                int l = i - k;
                int r = i - 1;

                if(l >= 0){
                    ans[i] = prefix[r] - (l > 0 ? prefix[l-1] : 0);
                }
                else{
                    // [0 ... r]
                    if(r >= 0)
                        ans[i] = prefix[r];

                    // [n+l ... n-1]
                    l += n;
                    ans[i] += prefix[n-1] - (l > 0 ? prefix[l-1] : 0);
                }
            }
        }

        return ans;
    }
};