class Solution230 {
public:
    // �򵥵��������
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (--k == 0) {
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};