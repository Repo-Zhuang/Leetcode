/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> dic = {{"type", 0}, {"color", 1}, {"name", 2}};
        int res = 0, index = dic[ruleKey];
        for (auto item : items) {
            if (item[index] == ruleValue) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

