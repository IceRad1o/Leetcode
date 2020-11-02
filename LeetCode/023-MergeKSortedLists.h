#include "utility.h"

class Solution {
public:
    // 1.˳��鲢

    // 2. �鲢�ϲ� ���ǵݹ顸���ϻ������Ĺ��� ʱ�临�Ӷ�O(logk*kn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r)
    {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergetwo(merge(lists, l, mid), merge(lists, mid + 1, r));
    }


    // 3. ���ȶ���


    // ���ߺ����� �ϲ�������������
    ListNode* mergetwo(ListNode* a, ListNode* b)
    {
        ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }

        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
};
