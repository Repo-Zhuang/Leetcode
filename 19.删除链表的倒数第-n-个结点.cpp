/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* SlowPtr = dummyNode;
        ListNode* QuickPtr = dummyNode;
        ListNode* tmp;

        while (n--) QuickPtr = QuickPtr->next;
        while (QuickPtr->next != nullptr)
        {
            QuickPtr = QuickPtr->next;
            SlowPtr = SlowPtr->next;
        }
        tmp = SlowPtr->next;
        SlowPtr->next = SlowPtr->next->next;
        delete tmp;
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};
// @lc code=end

