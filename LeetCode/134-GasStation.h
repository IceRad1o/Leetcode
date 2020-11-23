#include "utility.h"

class Solution134 {
public:
    // 利用笔记一次遍历
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, run = 0, start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            run += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            if (run < 0) {
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1 : start;
    }

    // 优化搜素，跳过中间的搜索。
    int canCompleteCircuit_v2(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            }
            else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }

    // 暴力解
    int canCompleteCircuit_v1(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            left[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < n; i++) {
            if (left[i] < 0) continue;
            else {
                int cost = 0;
                for (int j = i; j < n; j++) {
                    if (cost < 0) break;
                    cost += left[j];
                }
                for (int k = 0; k < i; k++) {
                    if (cost < 0) break;
                    cost += left[k];
                }
                if (cost >= 0) return i;
            }
        }
        return -1;
    }
};

void test134(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = { 3, 4, 5, 1, 2 };
    Solution134 s134;
    s134.canCompleteCircuit(gas, cost);
}