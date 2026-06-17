/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void buildStack(ListNode* head, stack<int>& st){
        ListNode* temp = head;
    
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

    }
    
    int pairSum(ListNode* head) {
        int ans = 0;
        stack<int> st;
        buildStack(head, st);

        ListNode* temp = head;

        while(temp){
            ans = max(ans, (temp->val + st.top()));
            st.pop();
            temp = temp->next;
        }

        return ans;
    }
};