/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
private:
    // 记录所有子树以及出现的次数
    unordered_map<string, int> subTrees;
    // 记录重复的子树根节点
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
    
    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }

        // 先算左右子树的序列化结果
        string left = serialize(root->left);
        string right = serialize(root->right);

        string myself = left + "," + right + "," + to_string(root->val);

        int freq = subTrees[myself];
        // 多次重复也只会被加入结果集一次
        if (freq == 1) {
            res.push_back(root);
        }
        // 给子树对应的出现次数加一
        subTrees[myself]++;

        return myself;
    }
};
// @lc code=end

