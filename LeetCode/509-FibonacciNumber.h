class Solution509 {
public:
    // ��һ���������dp����򵥵�����

    // 1.�����ݹ飬��Ȼ���ڴ����ظ������������
    int fib_bruteforce(int N) {
        if (N < 2) return N;
        return fib(N - 1) + fib(N - 2);
    }

    // 2.����¼�ݹ�, ��ʵ�Ͷ�̬�滮��˼·һ����ֻ����memo�Ǵ������²������
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

    // 3.dp ��ʵ���Ǵ������ϵ��ƣ�����dpһ�㶼�Ǵ���forѭ��
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

    // 4.���� ֻ����������������ʵ����״̬ѹ����dp��POJ2411����һ������
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