/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        bool result = true;
        if ((coordinates[0] ) % 2 != 0 ) result = false;
        if ((coordinates[1] ) % 2 ==0 ) result = !result;
        return  result;
    }
};
// @lc code=end

