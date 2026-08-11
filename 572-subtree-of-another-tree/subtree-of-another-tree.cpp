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
    bool ans = false;
    bool match(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;

        if (!root1 || !root2)
            return false;

        if (root1->val != root2->val)
            return false;

        return match(root1->left, root2->left) &&
            match(root1->right, root2->right);
    }
    void traverse(TreeNode* root, TreeNode* subroot){
        if(!root) return;
        
        if(root->val == subroot->val) 
            if(match(root, subroot))
                ans = true;

        traverse(root->left, subroot);
        traverse(root->right, subroot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverse(root, subRoot);

        return ans;
    }
};