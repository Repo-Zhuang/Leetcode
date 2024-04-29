/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effortTo(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            fill(effortTo[i].begin(), effortTo[i].end(), INT_MAX);
        }

        effortTo[0][0] = 0;

        priority_queue<State, vector<State>, greater<State>> pq;

        pq.emplace(State{0, 0, 0});
        while (!pq.empty()) {
            State curState = pq.top();
            pq.pop();

            int curX = curState.x;
            int curY = curState.y;
            int curEffortFromStart = curState.effortFromStart;
    }
    }
};
// @lc code=end

