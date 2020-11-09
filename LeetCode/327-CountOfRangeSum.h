#include <vector>

// 可以用这题来学习线段树和树状数组等数据结构，简单的方法就是归并排序

class Solution327 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sums{ 0 };
        for (auto& v : nums) {
            s += v;
            sums.push_back(s);
        }
        return countmerge(sums, lower, upper, 0, sums.size() - 1);
    }

    int countmerge(vector<long>& sums, int lower, int upper, int left, int right) {
        if (right == left) return 0;
        int mid = (left + right) >> 1;
        int c1 = countmerge(sums, lower, upper, left, mid);
        int c2 = countmerge(sums, lower, upper, mid + 1, right);
        int count = c1 + c2;
        int m = mid + 1, n = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (m <= right && sums[m] - sums[i] < lower) m++;
            while (n <= right && sums[n] - sums[i] <= upper) n++;
            count += n - m;
        }
        // inplace_merge(sums.begin() + left, sums.begin() + mid + 1, sums.begin() + right + 1); 注意这里的边界条件
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sums[p2++];
            }
            else if (p2 > right) {
                sorted[p++] = sums[p1++];
            }
            else {
                if (sums[p1] < sums[p2]) {
                    sorted[p++] = sums[p1++];
                }
                else {
                    sorted[p++] = sums[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            sums[left + i] = sorted[i];
        }
        return count;
    }


    // O(n^2) 超时
    int countRangeSum_bruteforce(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper) {
                    count++;
                }
            }
            sum = 0;
        }
        return count;
    }
};

void test327()
{
    int a = -2147483648;
    std::vector<int> v{ -2, 5, -1 };
    Solution327 s327;
    cout << s327.countRangeSum(v, -2, 2);
}