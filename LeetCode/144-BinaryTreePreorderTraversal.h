#include<vector>
#include<stack>
#include "utility.h"
using std::vector;
using std::stack;

class Solution144 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root || !stk.empty()) {
            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            root = stk.top()->right;
            stk.pop();
        }
        return res;
    }
};