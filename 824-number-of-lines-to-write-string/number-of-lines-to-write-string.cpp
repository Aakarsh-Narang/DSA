class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int r = 1, c = 0;
        for(auto& ch:s){
            c += widths[ch-'a'];
            if(c > 100){
                r++;
                c = widths[ch-'a'];
            }
        }
        return {r, c};
    }
};