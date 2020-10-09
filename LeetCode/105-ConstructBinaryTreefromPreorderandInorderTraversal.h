

class Solution105 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder) {
        if (preStart > preorder.size() - 1 || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == preorder[preStart]) {
                index = i;
                break;
            }
        }
        root->left = helper(preStart + 1, inStart, index - 1, preorder, inorder);
        root->right = helper(preStart + index - inStart + 1, index + 1, inEnd, preorder, inorder);
        return root;
    }


};