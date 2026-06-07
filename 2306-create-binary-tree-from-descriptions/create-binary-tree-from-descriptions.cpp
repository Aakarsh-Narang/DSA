/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*    Algorithm:
        1. Create all Nodes and push values in a set, and store Node addresses in a hashmap as {key-> address}
        2. Link all children to their parents
        3. Keep deleting children from set, if a key is a child of some other node, delete it
        4. At the end only root node is left in the set
    */

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> nodeSet;
        unordered_map<int, TreeNode*> mp;

        for(auto& v : descriptions){
            // Insert all given nodes in the Tree
            nodeSet.insert(v[0]);
            nodeSet.insert(v[1]);

            // Create all give nodes in the Tree
            if(!mp.count(v[0])){
                TreeNode* parent = new TreeNode(v[0]);
                mp[v[0]] = parent;
            }
            if(!mp.count(v[1])){
                TreeNode* child = new TreeNode(v[1]);
                mp[v[1]] = child;
            }
        }

        for(auto& v : descriptions){
            int parent = v[0], child = v[1];
            // Link parent to child
            if(v[2]){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }

            // Erase Child
            if(nodeSet.count(child)){
                nodeSet.erase(child);
            }
        }
        // Now only root node lives inside the Set
        int root = *nodeSet.begin();

        return mp[root];
    }
};