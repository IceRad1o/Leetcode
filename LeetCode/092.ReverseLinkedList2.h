// 头插法的简单应用，有一个坑是记得初始化step=m 不然直接--m会导致下面n-m数值不对
class Solution92 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0), * prev = &dummy;
        prev->next = head;
        int step = m;
        while (--step) {
            prev = prev->next;
        }
        ListNode* cur = prev->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy.next;
    }
};