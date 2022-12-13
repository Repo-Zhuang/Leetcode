/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = 0;
        for (auto c : sentence) {
            n |= 1 << (c - 'a');
        }
        return n == (1 << 26) - 1;
    }
};
// @lc code=end

