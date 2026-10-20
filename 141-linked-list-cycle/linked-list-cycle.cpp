/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            // If cycle exits both pointers will definitely meet
            if(slow == fast) return true;
        }
        // If no cycle exists fast will reach NULL eventually & loop will terminate
        return false;
    }
};