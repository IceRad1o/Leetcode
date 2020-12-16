#include "utility.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cal = head;
        int len = 0;
        while (cal != nullptr) {
            cal = cal->next;
            len++;
        }
        ListNode dummy(0);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        prev->next = head;
        while (len >= k) {
            for(int i=0; i<k-1; i++){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
            }
            prev = cur;
            cur = prev->next;
            len -= k;
        }
        return dummy.next;
    }
};