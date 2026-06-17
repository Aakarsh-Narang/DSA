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
    int getLen(ListNode* head){
        ListNode* temp = head;
        int len = 0;

        while(temp){
            len++;
            temp = temp->next;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = getLen(head), cnt = 0;
        int target = len/2 + 1 ;

    
        ListNode* temp = head;
        while(temp){
            if(cnt+1 == target) return temp;

            cnt++;
            temp = temp->next;
        }

        return head;
    }
};