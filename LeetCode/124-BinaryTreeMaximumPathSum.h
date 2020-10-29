class Solution124 {
public:
    int maxPathSum(TreeNode* root, int& val) {
        if (root == nullptr) return 0;
        int left = max(maxPathSum(root->left, val), 0);
        int right = max(maxPathSum(root->right, val), 0);
        int sum = root->val + left + right;
        val = max(val, sum);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};