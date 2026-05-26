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
    int ans = 1e8;
    void traverse(TreeNode* root, int depth){
        if(!root) return;
        if(!root->left && !root->right){
            ans = min(ans, depth);
            return;
        }
            
        traverse(root->left, depth+1);
        traverse(root->right, depth+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        traverse(root, 1);
        return ans;
    }
};