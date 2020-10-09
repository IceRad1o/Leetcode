#include<vector>
using std::vector;

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int len = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            int lo = i + 1, hi = len - 1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] < target) {
                    lo++;
                    while (lo < hi && nums[lo] == nums[lo - 1]) { lo++; }
                }
                else if (nums[lo] + nums[hi] > target) {
                    hi--;

                }
                else {
                    vector<int> v{ nums[i],nums[lo],nums[hi] };
                    res.push_back(v);
                    lo++;
                    hi--;
                    while (lo < hi && nums[lo] == nums[lo - 1]) { lo++; }
                    while (lo < hi && nums[hi] == nums[hi + 1]) { hi--; }
                }
            }

        }
        return res;
    }
};