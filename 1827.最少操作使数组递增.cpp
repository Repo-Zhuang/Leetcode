/*
 * @lc app=leetcode.cn id=1827 lang=cpp
 *
 * [1827] 最少操作使数组递增
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return result;
    }
};
// @lc code=end

