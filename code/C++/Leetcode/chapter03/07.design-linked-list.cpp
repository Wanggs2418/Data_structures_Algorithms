#include <iostream>
#include <vector>

using namespace std;

//此处使用虚拟头节点设计单链表
class MyLinkedList {
public:
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr){}
    };
    
    // 初始化该对象
    MyLinkedList() {
        _size = 0;
        _dummyHead = new LinkedNode(0);
    }
    // 获取链表中下标为 index 的节点的值，不存在则返回 -1
    int get(int index) {
        // 输入值前置判断
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        // index从0开始
        LinkedNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    // 将值为 val 的节点插入到第一个元素前
    void addAtHead(int val) {
        // 创建新节点
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        // 注意长度增加
        _size++;
    }
    //同理，追加到最后一个元素后
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    // 插入到index节点之前
    //如果index为列表长度，则追加val到链表末尾；如果index大于列表长度，则不会插入到链表中
    void addAtIndex(int index, int val) {
        LinkedNode* newNode = new LinkedNode(val);

        if(index > _size) return;
        if(index < 0) index = 0;
        LinkedNode* cur = _dummyHead;
        
        while(index--) {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
        _size++;        
    }

    //在index有效的前提下，删除下标为index的节点
    void deleteAtIndex(int index) {
        if (index < 0 || index > (_size - 1)) return;
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
    //打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 10);
    linkedList.printLinkedList();
    linkedList.get(10);
    linkedList.deleteAtIndex(1);
    linkedList.get(1);
    linkedList.printLinkedList();
}
