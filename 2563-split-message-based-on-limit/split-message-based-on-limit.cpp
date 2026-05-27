class Solution {
public:
    bool canSplit(string& message, int& limit, int b){
        long long aChars = 0, suffixChars;
        int nb = log10(b) + 1;

        for(int len = 1, start = 1; start <= b; len++, start *= 10){
            int end = min(b, start * 10 - 1);
            aChars += 1LL * (end - start + 1) * len;
        }

        // for each suffix : 3 - <,/,> & n - digits in b 
        suffixChars = aChars + b * (3 + nb);

        long long totalLen = suffixChars + message.size();
        long long allowedLen = b * limit;  // No of fragments * limit of each fragment

        // cout<< totalLen;
        return totalLen <= allowedLen;
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        vector<string> ans;
        int partitions;
        
        for(partitions = 1; partitions <= n; partitions++){
            if(canSplit(message, limit, partitions)){
                break;
            }
        }
        if(!canSplit(message, limit, partitions)) return {};

        int nb = log10(partitions) + 1;
        string b = to_string(partitions);

        int idx = 0;
        for(int a = 1; a <= partitions; a++){
            int na = to_string(a).length();
            int suffixLen = na + nb + 3;
            int stringLen = limit - suffixLen;
            string messagePart = (a == partitions) ? message.substr(idx) : message.substr(idx, stringLen);
            string curr = messagePart + "<" + to_string(a) + "/" + b + ">";
            idx += stringLen;
            ans.push_back(curr);
        }
        return ans;
    }
};