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
        // 1. ���Ƹ��ڵ㣬������ ��ԭ�ڵ� -> �½ڵ㡱 �� Map ӳ��
        while (cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        // 2. ����������� next �� random ָ��
        while (cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        // 3. �����������ͷ�ڵ�
        return map[head];
    }


};