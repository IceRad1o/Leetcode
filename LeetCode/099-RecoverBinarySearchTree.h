class Solution99 {
public:
    void recoverTree_v2(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;

        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->val < pred->val) {
                y = root;
                if (x == nullptr) {
                    x = pred;
                }
                else break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }

    // inorder traverse tree -> get array -> find wrong value -> traverse again and recover
    void recoverTree_v1(TreeNode* root) {
        vector<int> inorder;
        traverse(root, inorder);
        int x = -1, y = -1;
        bool modified = false;
        for (int i = 0; i < inorder.size() - 1; ++i) {
            if (inorder[i] > inorder[i + 1]) {
                y = inorder[i + 1];
                if (!modified) {
                    x = inorder[i];
                    modified = true;
                }
            }
        }
        recover(root, 2, x, y);
    }

    // morries traverse
    void recoverTree_v3(TreeNode* root) {
        TreeNode* x = nullptr, * y = nullptr, * pred = nullptr, * predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    if (pred != nullptr && root->val < pred->val) {
                        y = root;
                        if (x == nullptr) {
                            x = pred;
                        }
                    }
                    pred = root;

                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
private:
    void traverse(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return;
        traverse(root->left, nums);
        nums.push_back(root->val);
        traverse(root->right, nums);
    }

    void recover(TreeNode* r, int count, int x, int y) {
        if (r == nullptr) return;
        if (r->val == x || r->val == y) {
            r->val = r->val == x ? y : x;
            if (--count == 0) {
                return;
            }
        }
        recover(r->left, count, x, y);
        recover(r->right, count, x, y);
    }
};