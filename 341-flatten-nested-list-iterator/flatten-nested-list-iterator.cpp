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
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n - 1; i >= 0; i--){
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        // Precuatinary Check, ATQ function won't be called if stack is empty 
        if(!st.empty()){
            int num = st.top().getInteger();
            st.pop();
            return num;
        }
        return -1;
    }
    
    bool hasNext() {
        // If list on top, open it first (in reverse)
        while(!st.empty() && !st.top().isInteger()){
            auto v = st.top().getList();
            st.pop();
            int ls = v.size();
            for(int i = ls-1; i>=0; i--){
                st.push(v[i]);
            }
        }
        // Return true if stack not empty & integer on top
        if(!st.empty() && st.top().isInteger()){
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