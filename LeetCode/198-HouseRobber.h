class Solution198 {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int* dp = new int[len];
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[len - 1];
    }
};