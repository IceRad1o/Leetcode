#include "utility.h"
#include <stack>
#include <vector>
using std::stack;
using std::vector;

class Solution98 {
public:

    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> seq;
        long long prev = (long long)INT_MIN - 1;
        while (root || !stk.empty())
        {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            TreeNode* node = stk.top();
            stk.pop();
            if (node->val <= prev) {
                return false;
            }
            prev = node->val;
            root = node->right;
        }
        return true;
    }
};