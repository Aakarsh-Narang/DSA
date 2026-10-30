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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, *pb = headB;
        while(pa || pb){
            if(pa == pb) return pa;

            pa = (pa == NULL) ? headB : pa->next;
            pb = (pb == NULL) ? headA : pb->next;
        }

        return nullptr;
    }
};