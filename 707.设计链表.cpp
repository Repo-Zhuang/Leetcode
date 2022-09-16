/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(NULL){}
    };
    
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > _size -1)
            return -1;
        ListNode* cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* NewNode = new ListNode(val);
        NewNode->next = _dummyHead->next;
        _dummyHead->next = NewNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* NewNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = NewNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        
        ListNode* NewNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        NewNode->next = cur->next;
        cur->next = NewNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size)
            return;
        ListNode* tmp;
        ListNode* cur = _dummyHead;
        while (index--)
        {
            cur = cur->next;
        }
        tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

