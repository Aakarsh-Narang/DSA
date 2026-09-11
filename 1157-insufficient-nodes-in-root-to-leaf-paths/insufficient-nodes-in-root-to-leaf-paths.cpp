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
    long long traverse(TreeNode* root, int currSum, int limit){
        if(!root) return -1e9;
        if(!root->left && !root->right){
            return root->val;
        }

        int left = traverse(root->left, currSum + (root->left ? root->left->val : 0), limit);
        int right = traverse(root->right, currSum + (root->right ? root->right->val : 0), limit);

        if(left + currSum < limit)
            root->left = NULL;

        if(right + currSum < limit)
            root->right = NULL;

        return max(left, right) + root->val;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return nullptr;

                if(traverse(root, root->val, limit) < limit)
            return nullptr;

        return root;
    }
};