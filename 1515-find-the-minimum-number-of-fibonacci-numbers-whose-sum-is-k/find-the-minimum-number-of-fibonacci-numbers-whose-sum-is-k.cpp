class Solution {
public:
    int solve(vector<int>& fibo, int target, int indx){
        if(indx < 0) return -1;
        if(target == 0) return 0;
        for(int i = indx; i >= 0; i--){
            if((target - fibo[i]) < 0) continue;
            int cnt = solve(fibo, target - fibo[i], i-1);

            if(cnt == -1) return cnt;
            else return cnt + 1; 
        }

        return -1;
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo;
    
        if(k == 0 || k == 1) return 1;

        int prev = 0, curr = 1; 
        fibo.push_back(0);
        fibo.push_back(1);

        while(curr <= k){
            int next = prev + curr;
            prev = curr;
            curr = next;
            
            fibo.push_back(curr);
        }

        // cout << fibo.size();
        return solve(fibo, k, fibo.size()-2);
    }
};