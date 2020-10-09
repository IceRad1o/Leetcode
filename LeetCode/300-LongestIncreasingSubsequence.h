class Solution300 {
public:
    // 贪心+二分查找: O(nlogn) d[len]记录了长度为len的上升子序列末尾元素的最小值
    int lengthOfLIS_greedy(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else {
                int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }

    // dp[i] 记录了以i为index结尾的最长上升子序列
    // 在nums[i]>nums[j](其中j<1) 的情况下 dp[i] = max(dp[j])+1
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int maxlen = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxlen = max(maxlen, dp[j] + 1);
                }
            }
            dp[i] = maxlen;
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};