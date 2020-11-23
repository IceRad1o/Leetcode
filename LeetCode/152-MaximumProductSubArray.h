class Solution152 {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> maxp(nums);
        vector<int> minp(nums);
        for (int i = 1; i < nums.size(); i++) {
            maxp[i] = max({ maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i] });
            minp[i] = min({ maxp[i - 1] * nums[i], minp[i - 1] * nums[i], nums[i] });
        }
        return *max_element(maxp.begin(), maxp.end());
    }
};