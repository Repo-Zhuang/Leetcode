/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return nullptr;
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);


    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int InStart, int InEnd, int PostStart, int PostEnd){
        if (InStart > InEnd) return nullptr;

        int index = 0;
        for(int i = InStart; i <= InEnd; i++){
            if(inorder[i] == postorder[PostEnd]){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(postorder[PostEnd]);
        int LeftSize = index - InStart;
        root->left = build(inorder,postorder,InStart,index-1,PostStart, PostStart+LeftSize-1);
        root->right= build(inorder,postorder,index+1,InEnd,PostStart+LeftSize, PostEnd-1);

        return root;

    }
};
// @lc code=end

