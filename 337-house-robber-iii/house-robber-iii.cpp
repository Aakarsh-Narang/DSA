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
    // Return pair : {rob, notRob}
    pair<int, int> solve(TreeNode* root){
        if(!root) return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int rob = left.second + root->val + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        auto loot = solve(root);

        return max(loot.first, loot.second);
    }
};