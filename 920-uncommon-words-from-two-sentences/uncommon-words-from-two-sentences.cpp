class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_multiset<string> st1, st2;
        vector<string> ans;

        s1 += " ";
        s2 += " ";

        for(int i = 0; i < s1.size(); i++){
            string temp = "";
            while(s1[i] != ' '){
                temp += s1[i];
                i++;
            }
            st1.insert(temp);
        }
        for(int i = 0; i < s2.size(); i++){
            string temp = "";
            while(s2[i] != ' '){
                temp += s2[i];
                i++;
            }
            st2.insert(temp);
        }

        for(int i = 0; i < s1.size(); i++){
            string w = "";
            while(s1[i] != ' '){
                w += s1[i];
                i++;
            }
            if(st1.count(w) && st2.count(w)) continue;
            if(st1.count(w) == 1 || st2.count(w) == 1){
                ans.push_back(w);
            }
        }

        for(int i = 0; i < s2.size(); i++){
            string w = "";
            while(s2[i] != ' '){
                w += s2[i];
                i++;
            }
            if(st1.count(w) && st2.count(w)) continue;
            if(st1.count(w) == 1 || st2.count(w) == 1){
                ans.push_back(w);
            }
        }

        return ans;
    }
};