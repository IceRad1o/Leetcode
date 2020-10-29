#include<iostream>
#include<vector>
using std::vector;

class Solution322 {
public:
    // �����dp��Ŀ   dp[i] = min(dp[i-coins[j]])+1 

    // �����ⷨ���������ݹ�Ĺ���
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

    // ����¼memo �����ύ��ʱ�������memo��Ϊ��ĳ�Ա�����Ǵ��뺯���У���Ϊmemo��һ���ܴ�����飬��������ʱ��̫��
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