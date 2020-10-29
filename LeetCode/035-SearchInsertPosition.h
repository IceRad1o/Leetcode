class Solution {
public:
    // 二分查找
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return left;
    }

    /* 顺序查找
    int searchInsert(vector<int>& nums, int target) {
        int result = -2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                result = i;
                break;
            }
        }
        if (result == -1) return 0;
        else if (result == -2) return nums.size();
        else return result;
    }
    */
};