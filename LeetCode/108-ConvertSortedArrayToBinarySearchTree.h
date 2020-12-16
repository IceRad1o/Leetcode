#include "utility.h"

class Solution108 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = helper(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* helper(vector<int>& nums, int low, int high)
    {
        if (low > high) return nullptr;
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, low, mid - 1);
        root->right = helper(nums, mid + 1, high);
        return root;
    }
};