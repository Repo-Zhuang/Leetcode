/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
     int maxDiameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int currentDiameter = left + right;
        if (currentDiameter > maxDiameter) maxDiameter = currentDiameter;

        return max(left, right) + 1;
        
    }
};
// @lc code=end

