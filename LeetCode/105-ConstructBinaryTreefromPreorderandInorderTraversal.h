#include "utility.h"

class Solution105 {
    unordered_map<int, int> imap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            imap[inorder[i]] = i;
        }
        return helper(0, n - 1, 0, n - 1, preorder, inorder);
    }

    TreeNode* helper(int prestart, int preend, int instart, int inend, vector<int>& preorder, vector<int>& inorder) {
        if (prestart > preend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int i = imap[preorder[prestart]];
        int leftlen = i - instart;
        root->left = helper(prestart + 1, prestart + leftlen, instart, i - 1, preorder, inorder);
        root->right = helper(prestart + leftlen + 1, preend, i + 1, inend, preorder, inorder);
        return root;
    }
};