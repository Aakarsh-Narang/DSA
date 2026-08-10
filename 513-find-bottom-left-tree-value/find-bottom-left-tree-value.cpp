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
    pair<int, int> find(TreeNode* root, int depth){
        // Base cases
        if(!root) return {-1, -1};
        if(!root->left && !root->right) return {root->val, depth};
        
        pair<int, int> left = find(root->left, depth + 1);
        pair<int, int> right = find(root->right, depth + 1);
        
        // cout << root->val << "\n"; 
        // cout << "Left: " << left.first <<" " << left.second << endl;
        // cout << "Right: " << right.first << " " << right.second<<endl<<endl;

        return left.second >= right.second ? left : right;
    }
    int findBottomLeftValue(TreeNode* root) {
        return find(root, 0).first;
    }
};