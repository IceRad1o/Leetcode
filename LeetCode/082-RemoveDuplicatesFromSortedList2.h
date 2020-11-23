#include "utility.h"

class Solution82 {
public:
    // µü´ú½â·¨
    ListNode* deleteDuplicates_nonrecur(ListNode* head) {
        ListNode dummy(0), * prev = &dummy, * cur = head;
        prev->next = cur;
        while (cur) {
            bool duplicated = false;
            while (cur->next && cur->val == cur->next->val) {
                ListNode* tmp = cur;
                cur = cur->next;
                duplicated = true;
                delete tmp;
            }
            // delete last
            if (duplicated) {
                ListNode* tmp = cur;
                cur = cur->next;
                delete tmp;
                continue;
            }
            prev->next = cur;
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur;
        return dummy.next;
    }

    // recursive
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
                ListNode* tmp = p;
                p = p->next;
                delete tmp;
            }
            delete head;
            return deleteDuplicates(p);
        }
        else {
            head->next = deleteDuplicates(p);
        }
        return head;
    }
};