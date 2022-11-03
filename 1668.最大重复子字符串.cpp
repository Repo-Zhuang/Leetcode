/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.find(word) == string::npos) return 0;
        int k = 1;
        string p = word;
        for (; word.size() <= sequence.size(); k++) {
            word += p;
            if (sequence.find(word) == string::npos) return k;
        }
        return k;
    }
};
// @lc code=end

