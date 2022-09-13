// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int Minlen = INT32_MAX;
        int Curlen;
        for (int j = 0; j < n; j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                Curlen = j - i + 1;
                Minlen = Curlen < Minlen ? Curlen : Minlen;
                sum -= nums[i++];
            }
        }
        return Minlen == INT32_MAX ? 0 : Minlen;
    }
};
// @lc code=end

