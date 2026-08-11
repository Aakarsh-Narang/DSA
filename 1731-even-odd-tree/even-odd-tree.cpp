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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            int prev = level % 2 == 0 ? INT_MAX : INT_MIN;
            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

                if(curr->val % 2 == level % 2){
                    if(level%2 == 0 && prev <= curr->val) return false; 
                    if(level%2 != 0 && prev >= curr->val) return false; 
                    // Everythings's fine
                }
                else{
                    return false;
                }
                prev = curr->val;
            }
            level++;
        }
        return true;
    }
};