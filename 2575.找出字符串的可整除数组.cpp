/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        long long cur = 0;
        for (char& c : word) {
            cur = (cur * 10 + (c - '0')) % m;
            res.push_back(cur == 0 ? 1 : 0);
        }
        return res;
    }
};
// @lc code=end

