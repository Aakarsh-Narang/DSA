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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>>q;
        unsigned long long len = 0;

        q.push({root, 0LL});
    
        while(!q.empty()){
            unsigned long long left = q.front().second, right = 0, sz = q.size();
            while(sz--){
                auto [node, indx] = q.front();
                q.pop();
                left = min(left, indx);
                right = max(right, indx);
                if(node->left) q.push({node->left, 2*indx});
                if(node->right) q.push({node->right, 2*indx+1});
            }

            len = max(len, right - left + 1);
        }
        return len;
    }
};