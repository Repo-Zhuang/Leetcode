/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        //用栈
        // if (s.empty()) return 1;
        // stack<char> brackets;
        // int num = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '(') brackets.push(s[i]);
        //     else {
        //         if (!brackets.empty() && brackets.top() == '(') {
        //             brackets.pop();
        //         }
        //         //')'需要添加的括号数量
        //         else  num++;
        //     }
        // }
        // return num + brackets.size();
        //计数
        int LBrackets = 0;
        int num = 0;
        for (auto c : s) {
            if (c == '(') LBrackets++;
            else if (c == ')' && LBrackets != 0) LBrackets--;
            else num++; 
        }
        return num + LBrackets;
    }
};
// @lc code=end

