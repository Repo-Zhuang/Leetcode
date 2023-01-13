/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        char count1[26] = {0};
        char count2[26] = {0};
        int result = INT_MAX;
        for (char c : s) {
            count1[c - 'a'] ++;
        }
        for (char c: target) {
            count2[c - 'a'] ++;
        }
        for (char c: target) {
            result = min(result, count1[c - 'a'] / count2[c - 'a']);
        }
        return result;
    }
};
// @lc code=end

