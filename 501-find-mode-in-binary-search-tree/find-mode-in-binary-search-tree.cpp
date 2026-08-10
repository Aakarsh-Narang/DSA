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
    int maxFreq = 0;
    vector<int> ans;

    void traverse(TreeNode* root, pair<int, int>& curr){
        if(!root) return;

        traverse(root->left, curr);

        if(root->val == curr.first){
            curr.second++;
        }
        else{
            curr = {root->val, 1};
        }

        if(curr.second > maxFreq){
            ans = {};
            maxFreq = curr.second;
        }
        if(curr.second == maxFreq){
            ans.push_back(root->val);
        }

        traverse(root->right, curr);
    }
    vector<int> findMode(TreeNode* root) {
        pair<int, int> curr = {-1, -1};

        traverse(root, curr);

        return ans;
    }
};