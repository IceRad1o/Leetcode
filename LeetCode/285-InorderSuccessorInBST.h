#include "utility.h"
class Solution285 {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        while (root) {
            if (p->val < root->val) {
                res = root;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return res;
    }
};