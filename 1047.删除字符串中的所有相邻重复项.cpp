/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> A;
        for (char c : s) {
            if (!A.empty()) {
                if (c == A.top()) {
                    A.pop();
                } 
                else {
                    A.push(c);
                }
            }
            else {
                A.push(c);
            }
        }
        s = ""; 
        while (!A.empty()) {
            s += A.top();
            A.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
// @lc code=end

