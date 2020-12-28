// 1. �ݹ�
// 2. ��̬�滮(3ά)

class Solution87 {
public:
	// dp
	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		int n = s1.size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, 0)));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j][1] = s1[i] == s2[j];
			}
		}
		// dp[i][j][len] = dp[i][j][k] && dp[i+k][j+k][len-k] 
		//                 dp[i][j+len-k][k] && dp[i+k][j][len-k] 
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				for (int j = 0; j <= n - len; j++) {
					for (int k = 1; k < len; k++) {
						if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
							dp[i][j][len] = 1;
							break;
						}
						if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
							dp[i][j][len] = 1;
							break;
						}
					}
				}
			}
		}
		return dp[0][0][n];
	}

	bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		return Recursion(s1, s2);
	}
	bool Recursion(string s1, string s2)
	{
		if (s1 == s2)
			return true;
		//��ֹ��ʱ����s1�������ַ���s2�в������ڣ�˵��s1������ô�ָ��s2�޷�ƥ�䣬ֱ�ӷ���false������Ż�Ч��
		string t1 = s1, t2 = s2;
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		if (t1 != t2)
			return false;
		//i��1��s1.size-1�����ܴ��±�0��ʼ�����ٷָ�1���ַ������������޷�����ѭ��
		for (int i = 1; i < s1.size(); i++)
		{
			//��s1�ָ��[0,i)[i,s1.size)��Ӧs2ƥ�������[0,i)[i,s1.size)Ҳ������[s2.size-i,s2.size)[0,s2.size()-i)
			bool flag1 = Recursion(s1.substr(0, i), s2.substr(0, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
			bool flag2 = Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
			if (flag1 || flag2)
				return true;
		}
		return false;
	}
};
