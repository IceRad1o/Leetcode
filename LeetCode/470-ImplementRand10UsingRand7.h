// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <stdlib.h>  // for rand,srand
#include <time.h>
int rand7() {
    srand(time(NULL));
    return rand() % 7 + 1;
}
// 首先理解 只要N>7 直接用就可以，比如rand10 对于1-7的生成，概率都是相同的
// 核心理念就是用 (rand7()-1)*7 + rand7() 来生成1-49个数
// 或者理解 randn-1 * 7 + rand7 就是生成 1到n*7的随机数

class Solution {
public:
    // 直接拒绝采样
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        while (num > 10) {
            num = (rand7() - 1) * 7 + rand7();
        }
        return num;
    }
    
    // 优化1
    int rand10_opt1() {
        int num = (rand7() - 1) * 7 + rand7();
        while (num > 40) {
            num = (rand7() - 1) * 7 + rand7();
        }
        return num % 10 + 1;
    }

    // 重复缩小范围
    int rand10_opt2() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            // 如果在40以内，那就直接返回
            if (num <= 40) return 1 + num % 10;
            // 说明刚才生成的在41-49之间，利用随机数再操作一遍
            num = (num - 40 - 1) * 7 + rand7();
            if (num <= 60) return 1 + num % 10;
            // 说明刚才生成的在61-63之间，利用随机数再操作一遍
            num = (num - 60 - 1) * 7 + rand7();
            if (num <= 20) return 1 + num % 10;
        }
    }

};