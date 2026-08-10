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
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return NULL;

        if(root1 && root2){
            root1->val += root2->val;
            root1->left = merge(root1->left, root2->left);
            root1->right = merge(root1->right, root2->right);
            return root1;
        }
        else if(root2){
            TreeNode* temp = new TreeNode(root2->val);
            temp->left = merge(root1, root2->left);
            temp->right = merge(root1, root2->right);
            return temp;
        }
        else{
            return root1;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};