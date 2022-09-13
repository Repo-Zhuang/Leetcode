/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> A (n, vector<int>(n, 0));
        int loop = n / 2;
        int startx = 0;
        int starty = 0;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--)
        {
            for ( j = starty; j < n - offset; j++)
            {
                A[startx][j] = count++;
            }

            for ( i = startx; i < n - offset; i++)
            {
                A[i][j] = count++;
            }

            for ( ; j > starty; j--)
            {
                A[i][j ] = count++;
            }

            for (; i > startx; i--)
            {
                A[i][j ] = count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if (n % 2)
        {
            A[n/2][n/2] = count;
        }
        return A;
    }
};
// @lc code=end

