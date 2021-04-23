/*
 * 删除链表的倒数第 N 个结点
 * 链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* tail = head;
        ListNode* del = head;

        while(n-1)
        {
            tail = tail->next;
            n--;
        }

        while(tail->next)
        {
            tail = tail->next;
            del = del->next;
        }

        if(del == head)
        {
            return head->next;
        }

        ListNode* cur = head;

        while(cur->next != del)
        {
            cur = cur->next;
        }

        cur->next = del->next;

        return head;

    }
};
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* help = new ListNode(0);
        help->next = head;
        ListNode* tail = help;
        ListNode* del = help;

        while(n)
        {
            tail = tail->next;
            n--;
        }

        tail = tail->next;

        while(tail != nullptr)
        {
            tail = tail->next;
            del = del->next;
        }

        del->next = del->next->next;

        return help->next;
    }
};
