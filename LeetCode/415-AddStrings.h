class Solution415 {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int over = 0;
        string ret;
        while (m >= 0 || n >= 0 || over)
        {
            int n1 = m >= 0 ? num1[m] - '0' : 0;
            int n2 = n >= 0 ? num2[n] - '0' : 0;
            char sum = (n1 + n2 + over) % 10 + '0';
            over = (n1 + n2 + over) / 10;
            ret.push_back(sum);
            m--;
            n--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};