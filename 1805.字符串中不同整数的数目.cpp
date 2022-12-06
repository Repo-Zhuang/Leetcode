/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> set;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] <= '9') {
                int j = i;
                while (word[j] <= '9' && j < n) j++;
                while (word[i] == '0' && i < j) i++;
                set.insert(word.substr(i, j - i));
                i = j;
            }
        }
        return set.size();  
    }
};

// @lc code=end

