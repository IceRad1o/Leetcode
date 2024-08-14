/*
    ����һ�� ����ƥ�� ���� '('��ջ��ֱ������ ')'. ������������ڳ�ջ��ʱ���������������Կ��Ե���������string
             ����һ����������C++û����Javaһ�� stack<Object>����ͬʱ���int��char������Ҫ�õ�����ջ��
             ����һ�뷨�ܼ򵥣����ǽ���ʵ��
    �������� ˳��ɨ���ַ��� 
 */
#include <iostream>
#include <cmath>
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
                    opers.push(c); // ������
                }
            }
        }
        if (hasnum) nums.push(num);
        // if (s[0] == '+' || s[0] == '-') nums.push(0); ��������ͷ�����ϣ����������������Ӧ�ö���������
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

    // ����2
    int calculate_v2(string& s)
    {
        stack<int>st;
        int temp = 0;//��¼��λ��
        int result = 0;//��¼ѹ��ջ������
        int symbol = 1;//��־������

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                temp = 10 * temp + (s[i] - '0');
            else if (s[i] == '+')
            {
                result += symbol * temp;
                symbol = 1;//����
                temp = 0;//����
            }
            else if (s[i] == '-')
            {
                result += symbol * temp;
                symbol = -1;//����
                temp = 0;
            }
            else if (s[i] == '(')//������Ϊֹ����Ľ���ͷ�����ӵ�ջ��
            {
                st.push(result);
                st.push(symbol);
                symbol = 1;
                result = 0;
            }
            else if (s[i] == ')')
            {
                result += symbol * temp;//���������ڵĽ��
                result *= st.top(); st.pop();//��ȡ��ջǰ��������
                result += st.top(); st.pop();//������ջǰ�Ľ��
                temp = 0;//���ã���Ϊ)֮ǰ�����֣�temp���ǲ���
            }
        }
        //ѭ���˳���ʱ�򣬿϶����һ�������֣��Ϸ����ʽ����Ҫ��result���ϸ����֣����ұ����˵����ڶ�λ��������
        return result + (symbol * temp);
    }
};




void test224() {
    Solution224_v1 s224;
    string expr = "1+(4+5)-2";
    int res = s224.calculate(expr);
    std::cout << res << "\n";
}