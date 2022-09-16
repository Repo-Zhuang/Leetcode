/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        ListNode* tmp;
        while (cur->next && cur->next->next)
        {
            tmp = cur->next;
            cur->next = cur->next->next;
            tmp ->next = tmp->next->next;
            cur->next->next = tmp;
            cur = cur->next->next;
        }
        
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};
// @lc code=end

