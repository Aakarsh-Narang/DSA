class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0, cntOnes = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cnt += cntOnes;
            }
            cntOnes += (s[i] == '1');
        }

        return cnt;
    }
};