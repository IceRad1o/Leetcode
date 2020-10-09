
class Solution102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            while (s--) {
                TreeNode* tmp = q.front();
                v.push_back(tmp->val);
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr)q.push(tmp->right);
                q.pop();
            }
            ret.push_back(v);
        }
        return ret;
    }
};