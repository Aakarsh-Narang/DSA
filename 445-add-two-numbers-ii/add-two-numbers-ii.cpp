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
    ListNode* reverseLL(ListNode* root){
        ListNode* curr = root;
        ListNode* prev = nullptr;
        int len = 0;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            len++;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode* head = new ListNode();
        ListNode* curr = head;
        int carry = 0;

        while(l1 || l2 || carry){
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = (val1 + val2 + carry);
            carry = sum/10;

            curr->next = new ListNode(sum%10);
            curr = curr->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return reverseLL(head->next);
    }
};