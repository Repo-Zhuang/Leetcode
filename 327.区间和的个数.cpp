/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {

private:
    vector<int> preSum;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        preSum.resize(nums.size()+1);
        for (int i = 1; i < preSum.size() - 1; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        int i = 0, j = 0;
        for 

    }
};
// @lc code=end

