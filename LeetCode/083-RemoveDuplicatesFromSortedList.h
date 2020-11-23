#include "utility.h"

class Solution83 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* prev = head, * cur = head->next;
        while (cur) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
            }
            else {
                prev = cur;
            }
            cur = prev->next;
        }
        return head;
    }

    ListNode* deleteDuplicates_cur(ListNode* head) {
        if (!head) return head;
        ListNode dummy(head->val + 1); //different from head
        dummy.next = head;
        recur(&dummy, head);
        return dummy.next;
    }
private:
    void recur(ListNode* prev, ListNode* cur)
    {
        if (cur == nullptr) return;
        if (prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
            recur(prev, prev->next);
        }
        else recur(prev->next, cur->next);
    }
};