#include "utility.h"

class Solution86 {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode *left = &left_dummy;
        ListNode *right = &right_dummy;
        for(ListNode *cur = head; cur ; cur = cur->next){
            if(cur->val<x){
                left->next = cur;
                left = cur;
            }
            else{
                right->next = cur;
                right = cur;
            }
        }
        left->next = right_dummy.next;
        right-> next = nullptr;
        return left_dummy.next;
    }
};