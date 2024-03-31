/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        res.push_back(root->val);

        vector<int> leftres = preorderTraversal(root->left);
        res.insert(res.end(), leftres.begin(), leftres.end());

        vector<int> rightres = preorderTraversal(root->right);

        res.insert(res.end(),rightres.begin(), rightres.end());
        return res;

    }
};
// @lc code=end

