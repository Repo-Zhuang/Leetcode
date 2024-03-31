#include <algorithm>
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
int maxvalue = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return maxvalue;
    }

    int traverse(TreeNode* root) {
        if (root == NULL) return 0;

        int leftvalue = traverse(root->left);
        int rightvalue = traverse(root->right);
        int currentvalue = root->val;
        if (leftvalue > 0) currentvalue=currentvalue+leftvalue;
        if (rightvalue > 0) currentvalue=currentvalue+rightvalue;

        maxvalue = max(maxvalue,currentvalue);

        int temp = max(root->val+leftvalue,root->val+rightvalue);
        temp = max(temp,root->val);
        
        return temp;
    }
};
// @lc code=end

