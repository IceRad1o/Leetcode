#include<vector>
#include<algorithm>
using std::vector;
using std::max;
using std::min;
class Solution {
public:
    // 4. 双指针 时间O(n) 空间O(1)
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }

    // 3. 单调栈 比起124，单调栈可以理解为横向计算的过程
    int trap_stack(vector<int>& height) {
        stack<int> stk;
        int cur = 0;
        int water = 0;
        while (cur < height.size())
        {
            while (!stk.empty() && height[cur] > height[stk.top()]) {
                int t = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int bound_height = min(height[cur], height[stk.top()]) - height[t];
                water += bound_height * (cur - stk.top() - 1);
            }
            stk.push(cur++);
        }
        return water;
    }

    // 2. 解决了1每次遍历最大高度的问题 O(n) 空间复杂度也是O(n)
    int trap(vector<int>& height) {
        int len = height.size();
        if (height.size() == 0) return 0;
        int ans = 0;
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        left[0] = height[0];
        for (int i = 1; i < len; i++) {
            left[i] = max(left[i - 1], height[i]);
        }
        right[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }
        for (int i = 1; i < len; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }

    // 1. 暴力解法 O(n^2)
    int trap_bruteforce(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        for (int i = 1; i < len; i++) {
            int maxleft = 0;
            int maxright = 0;
            for (int j = i; j >= 0; j--) {
                maxleft = max(maxleft, height[j]);
            }
            for (int k = i; k < len; k++) {
                maxright = max(maxright, height[k]);
            }
            ans += min(maxleft, maxright) - height[i];
        }
        return ans;
    }
};