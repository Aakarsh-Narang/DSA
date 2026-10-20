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
    int traverse(TreeNode* root, unordered_map<long long, int>& mp, long long currSum, int targetSum){
        if(!root) return 0;

        currSum += root->val;
        int curr = 0;
        if(mp.count(currSum - targetSum)){
            curr += mp[currSum - targetSum];
        }

        mp[currSum]++;

        int left = traverse(root->left, mp, currSum, targetSum);
        int right = traverse(root->right, mp, currSum, targetSum);
        
        mp[currSum]--;
        return left + right + curr;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        unordered_map<long long, int> mp;
        mp[0]++;

        return traverse(root, mp, 0LL, targetSum);
    }
};