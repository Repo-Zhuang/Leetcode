/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool judge1 = false, judge2 = false, judge3 = false, judge4 = false;
        int n = password.size();
        if (n < 8) return false;
        for (int i = 0; i < n; i++) {
            if (password[i] <= 'z' && password[i] >= 'a') judge1 = true;
            if (password[i] <= 'Z' && password[i] >= 'A') judge2 = true;
            if (password[i] <= '9' && password[i] >= '0') judge3 = true;
            if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' ||password[i] == '%' ||
            password[i] == '^' ||password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+')
            judge4 = true;
            if (i != n - 1 && password[i] == password[i + 1]) {
                return false;
            }
        }

        return judge1 && judge2 && judge3 && judge4;
    }
};
// @lc code=end

