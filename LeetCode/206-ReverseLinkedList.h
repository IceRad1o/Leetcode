#include "utility.h"
#include <stack>
using std::stack;


class Solution206 {
public:
    

    /*
    ͷ�巨 ����˵����  1 2 3 4 5-> 2 1 3 4 5-> 3 2 1 4 5
    cur����1����ԭ����ͷ���ڵ㣬 prev���Ǵ�����dummy�ڵ�
    */
    ListNode* reverseList_recur_prev(ListNode* head) {
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

    // �����ͷ�巨��˵������һ��ָ��
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        while (head)
        {
            ListNode* tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
        }
        return cur;
    }

    // use stack store the value and new listnode need more space than other method
    ListNode* reverseList_on(ListNode* head) {
        stack<ListNode*> stk;
        while (head) {
            stk.push(head);
            head = head->next;
        }
        ListNode dummy(-1);
        ListNode* ret = &dummy;
        while (!stk.empty()) {
            ret->next = new ListNode(stk.top()->val);
            stk.pop();
            ret = ret->next;
        }
        return dummy.next;
    }
};