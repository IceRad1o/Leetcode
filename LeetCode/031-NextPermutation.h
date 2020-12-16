#include<vector>
#include<algorithm>
using std::vector;
// 从后向前找就ok

class Solution31 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >i && nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i],nums[j]);
        }
        std::reverse(nums.begin()+i+1, nums.end());
    }
private:
    // my implementation, not elegant enough
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (j = i + 1; j < n; j++) {
            if (nums[j] <= nums[i]) {
                break;
            }
        }
        swap(nums[i], nums[j - 1]);
        reverse(nums.begin() + i + 1, nums.end());
    }

};