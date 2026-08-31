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
    int minDist = 1e9, maxDist = -1;
    void travel(ListNode* prev, ListNode* curr, int last, int first, int cnt){
        int nextVal;
        if(curr->next) nextVal = curr->next->val;
        else return;

        int currVal = curr->val, prevVal = prev->val;
        if((prevVal > currVal && currVal < nextVal) || (prevVal < currVal && currVal > nextVal)){
            if(last != -1){
                minDist = min(minDist, cnt - last);
                maxDist = max(maxDist, cnt - first);
            }
            if(last == -1) first = cnt;
            travel(curr, curr->next, cnt, first, cnt+1);
        }
        else{
            travel(curr, curr->next, last, first, cnt+1);
        }
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head->next || !head->next->next) return {-1, -1};

        travel(head, head->next, -1, -1, 1);
        if(minDist == 1e9 || maxDist == -1) return {-1, -1};

        return {minDist, maxDist};
    }
};