/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i = 0;
        while (s[i] != '0' && i < n) i++;
        if (i == n - 1) return true;
        else {
            for (; i < n; i++) {
                if (s[i] == '1') return false;
            }
        }
        return true;
        //return s.find("01") == string::npos;
    }
};
// @lc code=end

