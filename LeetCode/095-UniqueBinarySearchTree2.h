#include "utility.h"
class Solution95 {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        else return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_nodes = generate(start, i - 1);
            vector<TreeNode*> right_nodes = generate(i + 1, end);
            for (auto j : left_nodes) {
                for (auto k : right_nodes) {
                    TreeNode* node = new TreeNode(i);
                    node->left = j;
                    node->right = k;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};