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
    ListNode* deleteMiddle(ListNode* head) {
        int len = getLen(head), cnt = 0;
        ListNode* temp = head;
        
        if(len == 1) return {};
        if(len == 2){
            head->next = NULL;
            return head;
        } 

        int target = (len)/2;
        while(temp){
            cnt++;

            if(cnt == target) break;
           
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};