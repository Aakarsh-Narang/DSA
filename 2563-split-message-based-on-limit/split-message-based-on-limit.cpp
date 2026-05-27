class Solution {
public:
    bool canSplit(string& message, int& limit, int b){
        long long aChars = 0, suffixChars;
        // Digits in total number of partitions 'b'
        int nb = log10(b) + 1;

        // Counting total digits contributed by all 'a' values
        // Eg: for b = 13
        // 1-9   -> 9 * 1 digits
        // 10-13 -> 4 * 2 digits
        for(int len = 1, start = 1; start <= b; len++, start *= 10){
            // Ending number of current digit-length range
            int end = min(b, start * 10 - 1);

            // Count of numbers in this range * digits per number
            aChars += 1LL * (end - start + 1) * len;
        }

        // for each suffix : 3 - <,/,> & n - digits in b 
        // Total suffix chars =
        // chars from all 'a' values + fixed chars from every suffix
        suffixChars = aChars + b * (3 + nb);

        // Entire final string length after adding all suffixes
        long long totalLen = suffixChars + message.size();

        long long allowedLen = 1LL * b * limit;  // No of fragments * limit of each fragment

        // Feasible if total required chars fit within total allowed chars
        return totalLen <= allowedLen;
    }

    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        vector<string> ans;
        int partitions;

        // Finding minimum feasible number of partitions
        for(partitions = 1; partitions <= n; partitions++){
            if(canSplit(message, limit, partitions)){
                break;
            }
        }

        // No valid partitioning possible
        if(!canSplit(message, limit, partitions))
            return {};

        // Digits in total partitions count
        int nb = log10(partitions) + 1;

        string b = to_string(partitions);
        int idx = 0;

        // Constructing each partition
        for(int a = 1; a <= partitions; a++){
            // Digits in current partition index
            int na = log10(a) + 1;

            // Total suffix length for current partition
            int suffixLen = na + nb + 3;

            // Actual message chars we can store in this partition
            int stringLen = limit - suffixLen;

            // Last partition can take remaining chars
            string messagePart = (a == partitions) ? message.substr(idx) : message.substr(idx, stringLen);

            string curr = messagePart + "<" + to_string(a) + "/" + b + ">";

            idx += stringLen;   // Update string pointer
            ans.push_back(curr);
        }
        return ans;
    }
};