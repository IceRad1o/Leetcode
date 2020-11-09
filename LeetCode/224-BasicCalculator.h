/*
    方法一是 括号匹配 对于 '('入栈，直到遇到 ')'. 这里的问题在于出栈的时候数字是逆序，所以可以倒过来检索string
             还有一个问题在于C++没法像Java一样 stack<Object>里面同时存放int和char，所以要用到两个栈。
             方法一想法很简单，但是较难实现
    方法二是 顺序扫描字符串 
 */
#include <iostream>
#include <stack>
#include <string>
using std::stack;
using std::string;
class Solution224_v1 {
public:
    stack<char> opers;
    stack<int> nums;
    int calculate(string s) {
        int num = 0;
        int hasnum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (isdigit(c)) {
                num += pow(10, hasnum) * (c - '0');
                hasnum += 1;
            }
            else if (c != ' ') {
                if (hasnum != 0) {
                    nums.push(num);
                    num = 0;
                    hasnum = 0;
                }
                if (c == '(') {
                    nums.push(eval());
                    opers.pop(); // pop ')'
                }
                else {
                    opers.push(c); // 操作符
                }
            }
        }
        if (hasnum) nums.push(num);
        // if (s[0] == '+' || s[0] == '-') nums.push(0); 用来处理头部符合，这里测试用例给的应该都是正常的
        return eval();
    }
    int eval() {
        int result = nums.top();
        nums.pop();
        while (!opers.empty() && opers.top() != ')') {
            if (opers.top() == '+') result += nums.top();
            else result -= nums.top();
            opers.pop();
            nums.pop();
        }
        return result;
    }

    // 方法2
    int calculate_v2(string& s)
    {
        stack<int>st;
        int temp = 0;//记录多位数
        int result = 0;//记录压入栈的数字
        int symbol = 1;//标志正负数

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                temp = 10 * temp + (s[i] - '0');
            else if (s[i] == '+')
            {
                result += symbol * temp;
                symbol = 1;//重置
                temp = 0;//重置
            }
            else if (s[i] == '-')
            {
                result += symbol * temp;
                symbol = -1;//负数
                temp = 0;
            }
            else if (s[i] == '(')//将迄今为止计算的结果和符号添加到栈上
            {
                st.push(result);
                st.push(symbol);
                symbol = 1;
                result = 0;
            }
            else if (s[i] == ')')
            {
                result += symbol * temp;//计算括号内的结果
                result *= st.top(); st.pop();//获取入栈前的正负号
                result += st.top(); st.pop();//加上入栈前的结果
                temp = 0;//重置，因为)之前是数字，temp还是不变
            }
        }
        //循环退出的时候，肯定最后一个是数字（合法表达式），要把result加上该数字，而且别忘了倒数第二位的正负号
        return result + (symbol * temp);
    }
};




void test224() {
    Solution224_v1 s224;
    string expr = "1+(4+5)-2";
    int res = s224.calculate(expr);
    std::cout << res << "\n";
}