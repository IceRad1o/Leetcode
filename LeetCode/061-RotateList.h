#include "utility.h"

class Solution61 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        ListNode* p = head;
        int len = 1;
        while (p->next) {
            len++;
            p = p->next;
        }
        p->next = head;
        int move = len - k % len;
        for (int i = 0; i < move; i++) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};