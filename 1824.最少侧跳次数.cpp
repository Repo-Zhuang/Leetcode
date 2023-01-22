/*
 * @lc app=leetcode.cn id=1824 lang=cpp
 *
 * [1824] 最少侧跳次数
 */

// @lc code=start
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int inf = INT_MAX;
        int array[3] = {1, 0, 1};

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) array[j] = inf;
            }    
            int Curmin = min({array[0], array[1], array[2]}) + 1;
            for (int j = 0; j < 3; ++j) {
                if (obstacles[i] != j + 1) {
                    array[j] = min(array[j], Curmin);
                }
            }
        }
        return min({array[0], array[1], array[2]});
    }
};
        
       
// @lc code=end

