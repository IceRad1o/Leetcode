class Solution876 {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};