#include<iostream>
#include<vector>
using std::vector;

class Solution322 {
public:
    // 经典的dp题目   dp[i] = min(dp[i-coins[j]])+1 

    // 暴力解法，用于理解递归的过程
    int coinChange_bruteforce(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int tmp = coinChange(coins, amount - coins[i]);
            if (tmp == -1) continue;
            res = min(res, tmp + 1);
        }
        return res == INT_MAX ? -1 : res;
    }

    // 备忘录memo 这里提交的时候最好是memo作为类的成员而不是传入函数中，因为memo是一个很大的数组，反复传入时间太长
    int coinChange_memo(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        memo[0] = 0;
        helper(coins, memo, amount);
        return memo[amount];
    }

    int helper(vector<int>& coins, vector<int>& memo, int amount)
    {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];
        int res = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int tmp = helper(coins, memo, amount - coins[i]);
            if (tmp == -1) continue;
            res = min(res, tmp + 1);
        }
        memo[amount] = res == INT_MAX ? -1 : res;
        return memo[amount];
    }

    // dp bottom-up
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

void test322()
{
    /*
    [186,419,83,408]
    6249
    */
    vector<int> coins{186,419,83,408};
    Solution322 s322;
    int n = s322.coinChange_memo(coins, 6249);
    std::cout << n << "\n";
   // int n = s322.coinChange(coins, 1000);
    //std::cout << n << "\n";
    //int n2 = s322.coinChange_bruteforce(coins, 1000);
   // std::cout << n2 << "\n";
}