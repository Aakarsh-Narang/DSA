/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* traverse(Node* head){
        if(!head) return NULL;
        
        while(head){
            if(head->child){
                Node* temp = traverse(head->child);
                // Handle Next
                temp->next = head->next;
                if(head->next)
                    head->next->prev = temp;
                // Handle Child 
                head->next = head->child;
                head->child->prev = head;
                head->child = NULL;
                head = temp;
            }
            if(!head->next) break;
            head = head->next;
        }
        return head;
    }
    Node* flatten(Node* head) {
        traverse(head);

        return head;
    }
};