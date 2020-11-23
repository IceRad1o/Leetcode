#include <vector>
#include <stack>
using std::vector;
using std::stack;
// ����ջ�ľ���Ӧ�ã�����˼�뻹�Ǵ�ÿ�����������߳���, O(n^2)�ᳬʱ
class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        stack<int> stk;
        heights.push_back(0);
        int res = 0;
        int i = 0;
        while (i < heights.size()) {
            if (stk.empty() || heights[i] > heights[stk.top()]) {
                stk.push(i++);
            }
            else {
                int top = stk.top();
                stk.pop();
                res = max(res,
                    heights[top] * (stk.empty() ? i : i - stk.top() - 1));
            }
        }
        return res;
    }
};

void test84()
{
    vector<int> heights{ 2,1,5,6,2,3 };
    Solution84 s84;

}