#include "utility.h"

// fast->f; slow->s;  a->开头到环开头长度  b->环的长度
// fast = 2s , fast = s + nb  =>  s = nb; 所以 slow的长度是n个环的长度。
// 而a + nb正好就是环入口
class Solution142 {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* slow2 = head;
                while (slow2 != slow) {
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};