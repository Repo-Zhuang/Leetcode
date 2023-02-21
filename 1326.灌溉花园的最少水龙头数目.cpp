/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> rightMost(n + 1);
        iota(rightMost.begin(), rightMost.end(), 0);
        for (int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            rightMost[start] = max(rightMost[start], end);
        }
        int last = 0, ret = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            last = max(last, rightMost[i]);
            if (i == last) {
                return -1;
            }
            if (i == pre) {
                ret++;
                pre = last;
            }
        }
        return ret;
    }
};
// @lc code=end

