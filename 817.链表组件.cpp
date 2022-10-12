/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> Set;
        int result = 0;
        int t = 0;
        for (int num : nums) {
            Set.insert(num);
        }
        while (head != nullptr) {
            if (Set.find(head->val) == Set.end()) {
                if (t == 1) result++;
                t = 0;
            }
            else t = 1;
            head = head->next;
        }

        return result + t;
    }
};
// @lc code=end

