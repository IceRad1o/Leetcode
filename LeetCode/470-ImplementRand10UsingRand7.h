// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <stdlib.h>  // for rand,srand
#include <time.h>
int rand7() {
    srand(time(NULL));
    return rand() % 7 + 1;
}
// ������� ֻҪN>7 ֱ���þͿ��ԣ�����rand10 ����1-7�����ɣ����ʶ�����ͬ��
// ������������� (rand7()-1)*7 + rand7() ������1-49����
// ������� randn-1 * 7 + rand7 �������� 1��n*7�������

class Solution {
public:
    // ֱ�Ӿܾ�����
    int rand10() {
        int num = (rand7() - 1) * 7 + rand7();
        while (num > 10) {
            num = (rand7() - 1) * 7 + rand7();
        }
        return num;
    }
    
    // �Ż�1
    int rand10_opt1() {
        int num = (rand7() - 1) * 7 + rand7();
        while (num > 40) {
            num = (rand7() - 1) * 7 + rand7();
        }
        return num % 10 + 1;
    }

    // �ظ���С��Χ
    int rand10_opt2() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            // �����40���ڣ��Ǿ�ֱ�ӷ���
            if (num <= 40) return 1 + num % 10;
            // ˵���ղ����ɵ���41-49֮�䣬����������ٲ���һ��
            num = (num - 40 - 1) * 7 + rand7();
            if (num <= 60) return 1 + num % 10;
            // ˵���ղ����ɵ���61-63֮�䣬����������ٲ���һ��
            num = (num - 60 - 1) * 7 + rand7();
            if (num <= 20) return 1 + num % 10;
        }
    }

};