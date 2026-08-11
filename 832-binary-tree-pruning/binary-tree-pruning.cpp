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
    bool prune(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        bool left = prune(root->left);
        bool right = prune(root->right);

        if(!left){
            root->left = NULL;
        }
        if(!right){
            root->right = NULL;
        }

        return root->val + left + right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(prune(root)) return root;

        return NULL;       
    }
};