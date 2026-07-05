class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        if(s.size() == 1) return t.size() >= 1;

        int m = t.size() , n = s.size(), i = 0, j = 0;
        vector<int> firstMatch(n, m), lastMatch(n, -1);

        while(i < n){
            while(j < m && t[j] != s[i]) j++;

            if(j < m){
                firstMatch[i] = j;
                j++;
            }
            else break;

            i++;
        }

        i = n-1, j = m-1;

        while(i >= 0){
            while(j >= 0 && t[j] != s[i]){
                j--;
            }
            if(j >= 0){
                lastMatch[i] = j;
                j--; 
            }
            else break;  // String exhausted

            i--;
        }

        if(firstMatch[n-1] < m) return true;  //Already a match

        int temp = 0;

        while(temp < n){
            if(temp == 0){
                if(lastMatch[1] >=1) return true;
            }
            else if(temp == n-1){
                if(firstMatch[n-2] <= m-2) return true;
            }
            else{
                bool vl = firstMatch[temp-1] < m;
                bool vr = lastMatch[temp+1] > -1;

                if(vl && vr){
                    if(lastMatch[temp+1] - firstMatch[temp-1] >= 2) return true;
                }
            }
            temp++;
        }
        return false;
    }
};