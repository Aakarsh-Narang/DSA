class Solution {
public:
    int height;

    int depth(TreeNode* root) {
        if (!root) return 0;

        if (!root->left && !root->right) return 1;

        int left = depth(root->left);
        int right = depth(root->right);

        return max(left, right) + 1;
    }

    void traverseAndPlace(TreeNode* root, vector<vector<string>>& ans, int depth, int idx) {
        if (!root) return;

        ans[depth][idx] = to_string(root->val);

        if (depth == height - 1)
            return;

        int offset = pow(2, height - depth - 2);

        int leftIdx = idx - offset;
        int rightIdx = idx + offset;

        traverseAndPlace(root->left, ans, depth + 1, leftIdx);
        traverseAndPlace(root->right, ans, depth + 1, rightIdx);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        height = depth(root);

        int width = pow(2, height) - 1;
        vector<vector<string>> ans(height, vector<string>(width, ""));

        int rootIdx = (width - 1) / 2;
        traverseAndPlace(root, ans, 0, rootIdx);

        return ans;
    }
};