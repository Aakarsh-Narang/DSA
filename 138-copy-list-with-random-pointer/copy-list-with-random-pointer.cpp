/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* build(Node* oldNode, unordered_map<Node*, Node*>& mp, unordered_map<Node*, bool>& vis){
        if(vis[oldNode]) return mp[oldNode];

        Node* newNode = new Node(oldNode->val);
        mp[oldNode] = newNode;
        vis[oldNode] = 1;

        if(oldNode->next != NULL){
            if(!vis[oldNode->next]){
                newNode->next = build(oldNode->next, mp, vis);
            }
            else{
                newNode->next = mp[oldNode->next];
            }
        }
        // Since we go all the way in recursively, so all the nodes have been built
        // Now we can just check & join them
        if(oldNode->random != NULL){
            newNode->random = mp[oldNode->random];
        }

        return newNode;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> vis;

        Node* newHead = build(head, mp, vis);

        return newHead;
    }
};