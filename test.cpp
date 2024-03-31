// @before-stub-for-debug-begin
#include <vector>
#include <iostream>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int res = 0;
int depth = 0;
int i =0;
class Solution {
public:
    int maxDepth(TreeNode* root) { 
        traverse(root);
        return res;

    }

    void traverse(TreeNode* root) {
        if (root == NULL) return;
        depth++;
        
        if (depth > res)res = depth;

    

        traverse(root->left);

        traverse(root->right);
        depth--;

    }
};
// @lc code=end

int main()
{
   
    TreeNode* root = new TreeNode(1, nullptr,  new TreeNode(2));
    Solution solution;
    solution.maxDepth(root);
    cout << res << endl;
    
}
