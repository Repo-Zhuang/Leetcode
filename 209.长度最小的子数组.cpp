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
        int i = 0, j = 0;
        int sum = 0;
        int Minlen = INT32_MAX;
        int Curlen;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target)  {
                Curlen = (i - j + 1);
                Minlen = Minlen < Curlen ? Minlen : Curlen;
                sum -= nums[j++];
            }
        }
        return Minlen == INT32_MAX ? 0 : Minlen;
    }
};
// @lc code=end

