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
    TreeNode* traverse(TreeNode* root){
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;

        TreeNode* leftTail = traverse(root->left);
        TreeNode* rightTail = traverse(root->right);

        if(leftTail){
            leftTail->right = root->right;
            root->right = root->left;

            root->left = NULL; 
        }

        if(rightTail) return rightTail;
        return leftTail;
    }
    void flatten(TreeNode* root) {
        traverse(root);
    }
};