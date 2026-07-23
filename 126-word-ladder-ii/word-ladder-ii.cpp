class Solution {
public:
    void dfsBuild(string& curr, string& beginWord, unordered_map<string, vector<string>>& parents, vector<string>& temp, vector<vector<string>>& ans) {
        if(curr == beginWord){
            temp.push_back(curr);
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            return;
        }

        temp.push_back(curr);

        for(auto& p : parents[curr]){
            dfsBuild(p, beginWord, parents, temp, ans);
        }

        temp.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        vector<vector<string>> ans;
        vector<string> temp;
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> dist;

        for(auto& w : wordList) st.insert(w);

        if(!st.count(endWord)) return {};

        queue<pair<string, int>> q;  // {word, dist/cost}

        q.push({beginWord, 1});
        dist[beginWord] = 1;

        while(!q.empty()){
            auto [word, cost] = q.front();
            q.pop();

            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(word[i] == ch) continue;

                    temp[i] = ch;
                    if(!st.count(temp)) continue;

                    if(!dist.count(temp)){
                        dist[temp] = cost + 1;
                        q.push({temp, cost + 1});
                        parents[temp].push_back(word);
                    }
                    else if(dist[temp] == cost + 1){
                        parents[temp].push_back(word);
                    }
                }
            }
        }

        if(!dist.count(endWord)) return {};

        dfsBuild(endWord, beginWord, parents, temp, ans);

        return ans;
    }
};