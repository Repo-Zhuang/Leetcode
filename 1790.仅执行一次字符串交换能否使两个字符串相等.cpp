/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        int num = 1;
        int first;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (num == 0) {
                    swap(s1[first], s1[i]);
                }
                first = i;
                num--;
            }
        }
        return s1 == s2 ? true : false;
    }
    
};
// @lc code=end

