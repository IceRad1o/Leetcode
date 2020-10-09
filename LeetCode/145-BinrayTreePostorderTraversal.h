#include<vector>
#include<stack>
#include "utility.h"
using std::vector;
using std::stack; 

class Solution145 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.push_back(root->val);
                prev = root;
                root = nullptr;
            }
            else {
                stk.push(root);
                root = root->right;
            }
        }
        return res;
    }
};
