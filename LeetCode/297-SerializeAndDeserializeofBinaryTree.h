#include "utility.h"
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (root == nullptr) return str;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int n = nodeQueue.size();
            while (n--) {
                TreeNode* tmp = nodeQueue.front();
                nodeQueue.pop();
                if (tmp == nullptr) {
                    str.push_back('$');
                }
                else {
                    str.append(to_string(tmp->val));
                }
                str.push_back(',');
                if (tmp) {
                    nodeQueue.push(tmp->left);
                    nodeQueue.push(tmp->right);
                }
            }
        }
        str.pop_back();
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        int len = data.size();
        int i = 0;
        vector<TreeNode*> vec;
        while (i < len) {
            string str = "";
            while (i < len && data[i] != ',') {
                str.push_back(data[i]);
                i++;
            }
            if (str == "$") {
                vec.push_back(nullptr);
            }
            else {
                TreeNode* node = new TreeNode(std::stoi(str));
                vec.push_back(node);
            }
            i++;
        }
        int k = 1;
        for (int j = 0; k < vec.size(); j++) {
            if (vec[j] == nullptr) continue;
            if (k < vec.size()) vec[j]->left = vec[k++];
            if (k < vec.size()) vec[j]->right = vec[k++];
        }
        return vec[0];
    }
};