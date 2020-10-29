class Solution509 {
public:
    // 是一个用于理解dp的最简单的例子

    // 1.暴力递归，显然存在大量重复计算的子问题
    int fib_bruteforce(int N) {
        if (N < 2) return N;
        return fib(N - 1) + fib(N - 2);
    }

    // 2.备忘录递归, 其实和动态规划的思路一样，只不过memo是从上往下拆分问题
    int fib_memo(int N) {
        if (N < 1) return 0;
        vector<int> helper(N + 1, 0);
        return memo(helper, N);
    }
    int memo(vector<int>& helper, int N)
    {
        if (N < 2) return N;
        if (helper[N] != 0) return helper[N];
        helper[N] = memo(helper, N - 1) + memo(helper, N - 2);
        return helper[N];
    }

    // 3.dp 其实就是从下往上递推，所以dp一般都是搭配for循环
    int fib_dp(int N) {
        if (N < 2) return N;
        int* dp = new int[N + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N];
    }

    // 4.迭代 只用了两个变量，其实就是状态压缩的dp，POJ2411就是一个例子
    int fib(int N) {
        if (N < 2) return N;
        int a = 0, b = 1;
        for (int i = 2; i <= N; i++) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};