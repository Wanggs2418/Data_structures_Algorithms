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
        ListNode* dummyHead = new ListNode(0); //设置虚拟头结点
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL) { 
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else {
                cur = cur->next;
            }
        }
        // 最后将辅助作用的虚拟节点删除
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};