/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int x = i;
            int boxnumber = 0;
            while(x) {
                boxnumber += x % 10;
                x = x / 10;
            }
            map[boxnumber]++;
            res = max(res, map[boxnumber]);
        }
        return res;
    }
};
// @lc code=end

