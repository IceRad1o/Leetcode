#include <limits.h>
#include <algorithm>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int cloest = INT_MAX;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (cloest > abs(sum - target)) {
                    cloest = abs(sum - target);
                    res = sum;
                }
                if (sum < target) {
                    j++;

                }
                else if (sum > target) {
                    k--;
                }
                else {
                    return sum;
                }
            }
        }
        return res;
    }
};