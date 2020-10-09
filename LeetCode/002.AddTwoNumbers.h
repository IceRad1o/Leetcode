#include "utility.h"

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        int over = 0;
        while (l1 != nullptr || l2 != nullptr || over) {
            int a = l1 == nullptr ? 0 : l1->val;
            int b = l2 == nullptr ? 0 : l2->val;
            int sum = (a + b + over) % 10;
            over = (a + b + over) / 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};