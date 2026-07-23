class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;

        for(auto& w : wordList) st.insert(w);

        queue<pair<string, int>> q;  // {word, dist}

        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, cost] = q.front();
            q.pop();

            // cout << word <<" : "<<cost<<endl;
            if(word == endWord) return cost;

            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(word[i] == ch) continue;
                    temp[i] = ch;
                    if(st.count(temp)){
                        q.push({temp, cost+1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};