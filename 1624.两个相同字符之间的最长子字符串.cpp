/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
       /*  int k;       
        int maxlen = -1;
        int curlen;
        int len = s.length();
        for (int i = 0;i < len; i++)
        {   
            k = -1;
            for (int j = i + 1; j < len; j++)
            {
                if (s[j] == s[i]) k = j;
            }
            if (k != -1) curlen = k - i - 1;
            if (curlen > maxlen) maxlen = curlen;
        }
        return maxlen; */

        vector<int> firstIndex(26, -1);
        int maxLength = -1;
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex[s[i] - 'a'] < 0) {
                firstIndex[s[i] - 'a'] = i;
            } else {
                maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
            }
        }
        return maxLength;

    }
};
// @lc code=end

