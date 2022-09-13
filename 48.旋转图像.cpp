/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        int n = matrix.size() - 1;
        for (int i = 0; i <= n/2; i++)
        {
            for (int j = i; j < n - i; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = temp;
            }
            
        }
        
    }
};
// @lc code=end