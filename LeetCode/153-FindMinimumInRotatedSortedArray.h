class Solution153 {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] <= nums[j]) {
                return nums[i];
            }
            int mid = (i + j) >> 1;
            if (nums[i] <= nums[mid]) { // use <= ,consider case: [2,1] should return1
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return -1;
    }
};