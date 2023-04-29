#include <iostream>
#include <vector>

using namespace std;

// 自定义链表形式
struct ListNode {
    int val;
    ListNode* next;
    // 成员初始化列表
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}

};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除的为头部节点
        while (head != NULL && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除非头部结点
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }
};