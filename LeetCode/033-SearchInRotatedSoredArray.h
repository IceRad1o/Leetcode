#include <vector>
using std::vector;
class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int mid;
        while (i <= j) {
            mid = (i + j) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] >= nums[i]) {
                if (nums[i] <= target && target < nums[mid]) {
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            else if (nums[mid] < nums[i]) {
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};