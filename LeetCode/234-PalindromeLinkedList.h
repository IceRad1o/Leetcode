#include "utility.h"
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head;
        if (head == nullptr) return true;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* lefthalf = head;
        ListNode* righthalf = reverselist(slow->next);
        while (righthalf) {
            if (lefthalf->val != righthalf->val) {
                return false;
            }
            lefthalf = lefthalf->next;
            righthalf = righthalf->next;
        }
        return true;
    }

    ListNode* reverselist(ListNode* head) {
        ListNode dummy(0), * prev = &dummy, * cur = head;
        prev->next = head;
        while (cur && cur->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy.next;
    }
};