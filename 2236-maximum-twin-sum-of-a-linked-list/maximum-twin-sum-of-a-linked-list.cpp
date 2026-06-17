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

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = curr->next;

        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;

        return curr;
    }

    ListNode* copyLL(ListNode* head){
        ListNode* newHead = new ListNode(head->val);
        ListNode* prev = newHead;
        head = head->next;
        

        while(head){
            ListNode* newHead = new ListNode(head->val);
            prev->next = newHead;
            prev = newHead;
            head = head->next;
        }
        
        return newHead;
    }

    void printLL(ListNode* temp){
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int pairSum(ListNode* head) {
        ListNode* newHead = reverseLL(copyLL(head));

        // printLL(newHead);
        // printLL(head);
        
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        int ans = 0;

        while(temp1 && temp2){
            ans = max(ans, temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return ans;
    }
};