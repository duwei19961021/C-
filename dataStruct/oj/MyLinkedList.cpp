/*
 * 设计链表
 * 链接：https://leetcode-cn.com/problems/design-linked-list/
 */

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    /** Initialize your data structure here. */
    MyLinkedList() {
        _head = new LinkedNode(0);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if(index >= _size)
        {
            return -1;
        }

        LinkedNode *ret = _head;
        while(index >= 0)
        {
            ret = ret->next;
            index--;
        }

        return ret->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _head->next;
        _head->next = newNode;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        LinkedNode *tail = _head;
        while(tail->next)
        {
            tail = tail->next;
        }
        tail->next = new LinkedNode(val);
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        LinkedNode *cur = _head;
        for(size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }

        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if(index >= _size)
        {
            return;
        }
        LinkedNode *cur = _head;
        for(size_t i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        _size--;
    }

private:
    LinkedNode* _head;
    size_t _size;
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
