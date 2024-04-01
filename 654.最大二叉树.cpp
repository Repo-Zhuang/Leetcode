/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int max = INT_MIN;
        int n = nums.size();
        if (n == 0) return nullptr;
        return traverse(nums, 0, n-1);
    
    }

    TreeNode* traverse(vector<int>& nums ,int IndexStart ,int IndexEnd) {
        if (IndexStart > IndexEnd) return nullptr;
        int index ;
        int max = INT_MIN;
        for (int i = IndexStart; i <= IndexEnd; i++){
            if(nums[i] > max) 
            {
                max = nums[i];
                index = i ;
            }

        }

        TreeNode* root = new TreeNode(max);
        root->left = traverse(nums, IndexStart,index -1);
        root->right = traverse(nums, index + 1, IndexEnd);
        return root;
      
    }
};
// @lc code=end

