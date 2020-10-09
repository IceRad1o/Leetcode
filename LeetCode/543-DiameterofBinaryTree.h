#include "utility.h"
class Solution543 {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root, res);
        return res;
    }
    int depth(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = depth(root->left, res);
        int right = depth(root->right, res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};



