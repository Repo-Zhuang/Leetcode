/*
 * @lc app=leetcode.cn id=1817 lang=cpp
 *
 * [1817] 查找用户活跃分钟数
 */

// @lc code=start
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> answer(k);
        unordered_map<int, unordered_set<int>> map;
        for (auto log : logs) {
            int ID = log[0], time = log[1];
            map[ID].emplace(time);
        }
         for (auto [ID, minutes] : map) {
            int activeCount = minutes.size();
            answer[activeCount - 1]++;
        }
        return answer;
    }
};
// @lc code=end

