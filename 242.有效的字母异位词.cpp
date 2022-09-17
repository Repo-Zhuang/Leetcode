/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int A[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            A[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            A[t[i] - 'a']--;
        }
        for (int count: A)
        {
            if (count != 0) return false;
        }
        return true;
        

    }
};
// @lc code=end

