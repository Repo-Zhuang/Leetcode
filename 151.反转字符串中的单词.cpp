/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        //去除多余空格，用快慢指针
        int p = 0;
        for (int q = 0; q < n; q++) {
            if (s[q] != ' ') {
                //如果不是第一单词，前面加空格
                if (p != 0) s[p++] = ' ';
                while (s[q] != ' ' && q < n) {
                        s[p++] = s[q++];
                }    
            }
        }
        //反转字符串
        s.resize(p);
        reverse(s.begin(), s.end()); 
        //反转每个单词
        for (int i = 0, j = 0; i < s.size(); i++) {
            if(s[i + 1] == ' ' || i == s.size() - 1) {
                reverse(s.begin() + j, s.begin() + i + 1);
                j = i + 2;
            }
        }
        //最后赋予0
        return s;
    }
    
};
// @lc code=end

