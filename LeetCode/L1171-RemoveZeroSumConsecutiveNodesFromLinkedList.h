#include "utility.h"
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0), * prev = &dummy;
        prev->next = head;
        unordered_map<int, ListNode*> prefixSum;
        prefixSum[0] = prev;
        int sum = 0, tmpsum = 0;
        ListNode* tmp = nullptr;
        for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
            sum += cur->val;
            if (prefixSum.find(sum) != prefixSum.end()) {
                tmp = prefixSum[sum]->next;
                prefixSum[sum]->next = cur->next;
                tmpsum = sum;
                while (tmp != cur) {
                    tmpsum += tmp->val;
                    prefixSum.erase(tmpsum);
                    tmp = tmp->next;
                }
            }
            else {
                prefixSum[sum] = cur;
            }
        }
        return dummy.next;
    }
};