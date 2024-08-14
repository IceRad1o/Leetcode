
class Solution55 {
public:
    // 3. greedy
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            if (reach >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }

    // 2. dp
    bool canJump(vector<int>& nums) {
        // dp[i] 表示从0出发到i剩下的最大步数
        if (nums.size() == 0) return false;
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return true;
    }

    // 1. backtracking-> return jump_backtraking(nums,0);
    bool jump_backtraking(vector<int>& nums, int position)
    {
        if (position == nums.size() - 1) {
            return true;
        }
        int furtherJump = min(position + nums[position], nums.size() - 1);
        for (int i = position + 1; i <= furtherJump; i++)
        {
            if (jump(nums, i))
                return true;
        }
        return false;
    }

};