#include "utility.h"
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder_left(root);
    }

    void inorder_left(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = stk.top();
        stk.pop();
        inorder_left(tmp->right);
        return tmp->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size() > 0;
    }
private:
    stack<TreeNode*> stk;
    int index;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */