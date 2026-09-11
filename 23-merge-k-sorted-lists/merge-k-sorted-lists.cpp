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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;

        for(auto& node : lists){
            if(node) 
                pq.push({node->val, node});
        }
        if(pq.size() == 0) return NULL;
        ListNode* head = pq.top().second;
        ListNode* curr = head;
        pq.pop();

        if(head->next) pq.push({head->next->val, head->next});

        while(!pq.empty()){
            auto [val, node] = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if(node->next){
                pq.push({node->next->val, node->next});
            }
        }

        return head;
    }
};