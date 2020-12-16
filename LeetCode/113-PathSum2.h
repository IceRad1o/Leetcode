#include <vector>
#include "utility.h"
using std::vector;
/*
和112一样，同样是dfs或者bfs解决
*/
class Solution113 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(root, sum, path, res);
        return res;
    }
 
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (root == nullptr) return;
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
        }
        dfs(root->left, sum, path, res);
        dfs(root->right, sum, path, res);
        path.pop_back();
    }


    // TODO bfs

};

void test113()
{
    TreeNode* node1 = new TreeNode(5);
    node1->left = new TreeNode(4);
    node1->right = new TreeNode(8);

    node1->left->left = new TreeNode(11);
    node1->left->left->left = new TreeNode(7);
    node1->left->left->right = new TreeNode(2);

    node1->right->left = new TreeNode(13);
    node1->right->right = new TreeNode(4);

    node1->right->right->left = new TreeNode(5);
    node1->right->right->right = new TreeNode(1);

    Solution113 s113;
    vector<vector<int>> result = s113.pathSum(node1, 22); 
    cout << "test113\n";
}