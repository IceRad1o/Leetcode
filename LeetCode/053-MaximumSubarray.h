#include<vector>
using std::vector;
class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int maxv = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum <= 0) sum = nums[i];
            else sum += nums[i];
            maxv = max(sum, maxv);
        }
        return maxv;
    }
};