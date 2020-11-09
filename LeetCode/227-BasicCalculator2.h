#include <iostream>
#include <stack>
#include <string>
using std::stack;
using std::string;

class Solution227 {
public:
    int calculate(string s) {
        int n = 0;
        char sign = '+';
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                n = n * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch (sign) {
                    int pre;
                case'+':
                    stk.push(n);
                    break;
                case'-':
                    stk.push(-n);
                    break;
                case'*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * n);
                    break;
                case'/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / n);
                    break;
                }
                sign = c;
                n = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};

void test227() {
    Solution227 s227;
    string expr = " 3/2 ";
    int res = s227.calculate(expr);
    std::cout << res << "\n";
}