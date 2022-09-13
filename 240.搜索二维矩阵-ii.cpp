/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int column = m - 1;
        for (;row <= n - 1 && column >=0;)
        {
            if (target > matrix[row][column])
                {
                    row++;
                }
                else if (target <  matrix[row][column])
                {
                    column--;
                }
                else
                {
                    return true;
                }
            
        }
        return false;
        
    }
};
// @lc code=end

