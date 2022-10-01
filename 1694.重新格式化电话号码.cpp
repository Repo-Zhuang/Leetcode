/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (auto c : number) {
            if (c != ' ' && c != '-') {
               s += c;
            }
        }
        int n = s.size();
        int pt = 0;
        string res; 
        while (n) {
            if (n > 4) {
                res += s.substr(pt, 3) + "-";
                pt += 3;
                n -= 3;
            }
            else {
                if (n == 4) {
                    res += s.substr(pt, 2) + "-" + s.substr(pt + 2, 2);
                }
                else {
                    res += s.substr(pt, n);
                }
                break;
            }
        }
        return res;
    }
};
// @lc code=end

