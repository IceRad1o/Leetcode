class Solution154 {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        if (nums[i] < nums[j]) return nums[i];
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (i > 0 && nums[i] < nums[i - 1]) {
                return nums[i];
            }
            if (nums[i] < nums[mid]) {
                i = mid + 1;
            }
            else if (nums[i] > nums[mid]) {
                j = mid;
            }
            else {
                i++;
            }
        }
        return nums[i];
    }
};