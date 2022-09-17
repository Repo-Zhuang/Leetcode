/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* QuickPtr = head;
        ListNode* SlowPtr = head;
        while (QuickPtr != nullptr && QuickPtr->next!= nullptr)
        {
            QuickPtr = QuickPtr->next->next;
            SlowPtr = SlowPtr->next;
            if (QuickPtr ==  SlowPtr)
            {
                ListNode* Pcur = QuickPtr;
                ListNode* Phead = head;
                while (Pcur != Phead) 
                {
                    Pcur = Pcur->next;
                    Phead = Phead->next;
                }
                return Pcur;
            }
        }
        return NULL;  
    }
};
// @lc code=end

