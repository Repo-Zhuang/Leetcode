// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem931.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        vector<vector<int>> dp(n,vector<int>(n + 2, 10001));

        for (int i = 0; i < n; i++) dp[0][i + 1] = matrix[0][i];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n ; j++) {
                temp = min(dp[i - 1][j - 1], dp[i - 1][j]);
                temp = min(temp, dp[i - 1][j+ 1]);
                dp[i][j] = temp + matrix[i][j - 1];
            }
        }
        int res = INT_MAX;
          for (int i = 1; i <= n; i++) {
            res = min(dp[n-1][i], res);
          }
        return res;
    }
};
// @lc code=end

