/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
class Solution {
public:
    string capitalizeTitle(string title) {
        int len = title.size();
        int l = 0, r = 0;
        while (r < len) {
            while (r < len && title[r] != ' ') ++r;
            if (r - l > 2) title[l++] = toupper(title[l]);
            while (l < r) title[l++] = tolower(title[l]);
            l++;
            r++;
        }
        return title;
    }
};
// @lc code=end

