/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    deque<NestedInteger> q;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = 0; i < n; i++){
            q.push_back(nestedList[i]);
        }
    }
    
    int next() {
        // Precuatinary Check, ATQ function won't be called if stack is empty 
        if(!q.empty()){
            int num = q.front().getInteger();
            q.pop_front();
            return num;
        }
        return -1;
    }
    
    bool hasNext() {
        // If list on top, open it first (in reverse)
        while(!q.empty() && !q.front().isInteger()){
            auto v = q.front().getList();
            q.pop_front();
            int ls = v.size();
            for(int i = ls-1; i >= 0; i--){
                q.push_front(v[i]);
            }
        }
        // Return true if stack not empty & integer on top
        if(!q.empty() && q.front().isInteger()){
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */