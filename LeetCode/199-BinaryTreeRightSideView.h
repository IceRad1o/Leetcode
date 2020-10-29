#include<queue>
#include<vector>
#include "utility.h"
using std::vector;
using std::queue;
class Solution199 {
public:
    //dfs
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        dfs(root, 0, view);
        return view;
    }
    void dfs(TreeNode* root, int depth, vector<int>& view) {
        if (root == nullptr) return;
        if (depth == view.size()) {  // // �����ǰ�ڵ�������Ȼ�û�г�����res�˵���ڸ�����µ�ǰ�ڵ��ǵ�һ�������ʵĽڵ㣬��˽���ǰ�ڵ����res��
            view.push_back(root->val);
        }
        depth++;
        dfs(root->right, depth, view);
        dfs(root->left, depth, view);
    }

    // bfs
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                if (len == 0) {
                    res.push_back(tmp->val);
                }
            }
        }
        return res;
    }
};