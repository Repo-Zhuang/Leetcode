// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem160.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* cur = headA;
        int n;
        while (cur != NULL) 
        {
            cur = cur->next;
            sizeA++;
        }
        cur = headB;
        while (cur != NULL) 
        {
            cur = cur->next;
            sizeB++;
        }
        std::cout << sizeA-sizeB<<endl;
        n = sizeA > sizeB ? (sizeA - sizeB) : (sizeB - sizeA);
        if (sizeA > sizeB)
        {
            while (n--) headA = headA->next;
        }
        else
        {
            while (n--) headB = headB->next;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
        
    }
};
// @lc code=end

