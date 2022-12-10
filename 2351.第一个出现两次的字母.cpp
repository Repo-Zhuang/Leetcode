/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution {
public:
    char repeatedCharacter(string s) {
        char t[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            t[s[i]-'a']++;
            if(t[s[i]-'a'] == 2) return s[i];
        }
        return -1;
    }
};
// @lc code=end

