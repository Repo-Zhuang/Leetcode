/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {

public:
    int fib(int N) {
        if (N == 0 || N == 1) return N;
        int dp_i_1 = 1, dp_i_2 = 0;
        for (int i = 2; i <= N; i++) {
            int dp_i = dp_i_1 + dp_i_2;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i_1;
        
    }
};

// @lc code=end

