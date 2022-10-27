/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (auto a : nums) {
            if (a == 0) return 0;
            if (a < 0) sign = -sign;
        }
        return sign;
    }
};
// @lc code=end

