#include "utility.h"
/*
1. 归并排序，找到中间节点，然后递归
2. 归并排序，迭代解法
3. 尝试快速排序
*/
class Solution148 {
public:
    // method1
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* l = sortList(head);
        ListNode* r = sortList(second);
        return mergesort(l, r);
    }

private:
    ListNode* mergesort(ListNode* first, ListNode* second) {
        ListNode* l = first;
        ListNode* r = second;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            }
            else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l == nullptr ? r : l;
        return dummy.next;
    }
};

void test148()
{
    ListNode *l1 = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(1);
    ListNode *l4 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    Solution148 s148;
    ListNode *t = s148.sortList(l1);
    while (t) {
        cout << t->val;
        t = t->next;
    }
}