/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> cal;//用long型防止int型数据运算溢出
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long num1 = cal.top();
                cal.pop();
                long num2 = cal.top();
                cal.pop();
                if (tokens[i] == "+") cal.push(num2 + num1);
                if (tokens[i] == "-") cal.push(num2 - num1);
                if (tokens[i] == "*") cal.push(num2 * num1);
                if (tokens[i] == "/") cal.push(num2 / num1);
            }
            else {
                cal.push(stoi(tokens[i]));
            }
        }
        return cal.top();
    }
};
// @lc code=end

