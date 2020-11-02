// 1.使用vector存储节点，双指针遍历 2.找到中间节点后 把后面的链表反转再和前面的链表merge

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // slow就是中左节点
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l2 = reverseList(l2); // 反转链表
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 && l2) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }

    }

    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr) return nullptr;
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;
        ListNode* cur = head;
        while (cur->next) {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;
        }
        return dummy.next;
    }
};