class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        // for me when you trust someone like a trusts b so  a-->b
        // so if town judge trust nobody a--X-> ...
        //everybody trusts town judge means for all i i-->a
        //Only one town judge 

        //we need to find the one with indegree of n and outdegree = 0 
        //we can have cycles too in this 

        //we will simply make two arrays and this will solve it 

        vector<int>inDegree(n+1, 0), outDegree(n+1,0);
        for(int i=0;i<m;i++){
            int a = trust[i][0], b = trust[i][1];
            inDegree[b]++;
            outDegree[a]++;
        }

        for(int i=1;i<=n;i++){
            if(inDegree[i]==n-1 && outDegree[i]==0)return i;
        }
        return -1;
    }
};