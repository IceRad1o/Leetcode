class Solution426 {
private:
    Node* pre = nullptr, * head = nullptr;
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }

    void dfs(Node* root) {
        if (root == nullptr) return;
        treeToDoublyList(root->left);
        if (pre != nullptr) {
            pre->right = root;
        }
        else {
            head = root;
        }
        root->left = pre;
        pre = root;
        treeToDoublyList(root->right);
    }
};