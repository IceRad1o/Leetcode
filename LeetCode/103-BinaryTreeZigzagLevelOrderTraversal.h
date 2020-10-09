class Solution103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        bool rev = true;
        while (!q.empty()) {
            //rev = rev==true?false:true;
            rev = !rev;
            int level = q.size();
            vector<int> v;
            while (level--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                v.push_back(node->val);
            }
            if (rev == true) {
                reverse(v.begin(), v.end());
            }
            ret.push_back(v);
        }
        return ret;
    }
};