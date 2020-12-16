#include "utility.h"
class Solution114 {
public:
    // O(n)  Space: O(1)
    void flatten_v2(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        helper(root);
    }
    TreeNode* helper(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* lnode = helper(root->left);
        TreeNode* rnode = helper(root->right);
        if (lnode == nullptr) {
            root->right = rnode;
            return root;
        }
        root->left = nullptr;
        root->right = lnode;
        while (lnode->right) {
            lnode = lnode->right;
        }
        lnode->right = rnode;
        return root;
    }
};

void test114() {
    TreeNode* r1 = new TreeNode(1);
    r1->left = new TreeNode(2);
    r1->left->left = new TreeNode(3);
    r1->left->right = new TreeNode(4);
    r1->right = new TreeNode(5);
    r1->right->right = new TreeNode(6);
    Solution114 s114;
    s114.flatten(r1);
    while (r1) {
        cout << r1->val << " ";
        r1 = r1->right;
    }
}