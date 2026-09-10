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
    int cnt = 0;
    pair<int, int> traverse(TreeNode* root){
        if(!root) return {0, 0};
        if(!root->left && !root->right){
            cnt++;
            return {root->val, 1};
        }

        auto [leftSum, leftCnt] = traverse(root->left);
        auto [rightSum, rightCnt] = traverse(root->right);

        if(leftCnt != 0 || rightCnt != 0)
        if(root->val == (leftSum + rightSum + root->val)/(leftCnt + rightCnt + 1)) cnt++;

        return {leftSum + rightSum + root->val, leftCnt + rightCnt + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return cnt;
    }
};