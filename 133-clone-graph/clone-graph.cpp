/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        queue<Node*> q; // stores nodes of the original graph to be explored
        unordered_map<int, Node*> mp;  // stores the adresses of the copies
        unordered_map<int, bool> vis;   // to check if a node has been visited/ pushed into queue already or not 

        Node* initial = new Node(node->val);
        q.push(node);
        mp[node->val] = initial;
        vis[node->val] = true;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            Node* copy = mp[curr->val];
            for(auto& nbr : curr->neighbors){
                if(!mp.count(nbr->val)){
                    Node* temp = new Node(nbr->val);
                    mp[nbr->val] = temp;
                }
                copy->neighbors.push_back(mp[nbr->val]);
                if(!vis[nbr->val]){
                    q.push(nbr);
                    vis[nbr->val] = true;
                }
            }
        }
        return initial;
    }
};