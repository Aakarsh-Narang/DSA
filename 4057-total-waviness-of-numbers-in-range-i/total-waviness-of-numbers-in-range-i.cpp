class Solution {
public:
    int cntWaviness(int num){
        if(num < 100) return 0;

        int cnt = 0;
        string n = to_string(num);

        for(int i = 1; i < n.size()-1; i++){
            if(n[i] > n[i-1] && n[i] > n[i+1]) cnt++;
            if(n[i] < n[i-1] && n[i] < n[i+1]) cnt++;
        }

        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(; num1 <= num2; num1++){
            ans += cntWaviness(num1);
        }

        return ans;
    }
};