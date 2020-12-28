#include "utility.h"
class Solution138 {
public:
    // Method2 
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* cur = head;
        // dup
        while (cur) {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        // get random
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // split two linked list
        cur = head->next;
        Node* prev = head, * res = head->next;
        while (cur->next) {
            prev->next = prev->next->next;
            cur->next = cur->next->next;
            prev = prev->next;
            cur = cur->next;
        }
        prev->next = nullptr;
        return res;
    }

    // method1
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        // 1. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 2. 构建新链表的 next 和 random 指向
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 3. 返回新链表的头节点
        return map[head];
    }


};