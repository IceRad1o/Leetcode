/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<stack>
#include "utility.h"
using std::vector;
using std::stack;
class Solution94 {
public:
    // µü´ú
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> stk;
        while(root || !stk.empty()){
            while(root){
            stk.push(root);
            root = root->left;
            }
            ret.push_back(stk.top()->val);
            root = stk.top()->right;
            stk.pop();
        }
        return ret;
    }

    // µÝ¹é
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    */
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

};