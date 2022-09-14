/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
    stack<char> brackets;
public:
    bool isValid(string s) {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                brackets.push(s[i]);
            }
            else{
                if (brackets.empty())
                {
                    return false;
                }
                char c = brackets.top();
                if (s[i] == ')' && c == '(' ||
                s[i] == ']' && c == '[' ||
                s[i] == '}' && c == '{')
                {
                    brackets.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return brackets.empty();
        
    }
};
// @lc code=end

