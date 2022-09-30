/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<int> op;
        
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '(') op.push(')');
            else if (s[i] == '{') op.push('}');
            else if (s[i] == '[') op.push(']');
            else if (!op.empty() && s[i] == op.top()) {
                op.pop();
            }
            else return false;
        }
        return op.empty();

    }
};
// @lc code=end

