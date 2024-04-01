/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(preorder.size() == 0) return nullptr;
       
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);

    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd) return nullptr;
        int rootVal = preorder[preStart];
        int index = 0;
        for (int i = 0; i < inorder.size(); i++){
           if (rootVal == inorder[i]){
                index = i;
                break;
           }
        }
        int leftSize = index - inStart;
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, inorder, preStart + 1,preStart+leftSize,inStart,index-1);
        root->right = build(preorder, inorder, preStart + leftSize + 1,preEnd,index+1,inEnd);


        return root;
    }
       

    
};
// @lc code=end

