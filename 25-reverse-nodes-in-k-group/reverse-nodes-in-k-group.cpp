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

    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end){
        ListNode *prev = end;
        ListNode *curr = start;

        while(curr != end){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev = new head
        // start = new tail
        return {prev, start};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *prevGroup = &dummy;
        ListNode *curr = head;

        while(curr){
            // Find end of current group
            ListNode *end = curr;
            for(int i = 0; i < k; i++){
                if(end == nullptr)
                    return dummy.next;
                end = end->next;
            }

            auto [newHead, newTail] = reverse(curr, end);

            prevGroup->next = newHead;
            newTail->next = end;

            prevGroup = newTail;
            curr = end;
        }

        return dummy.next;
    }
};