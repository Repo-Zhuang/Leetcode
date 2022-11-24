/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        int n = nums.size(), ans = 0, i0 = -1, i1 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) i0 = i;
            if (nums[i] >= left) i1 = i;
            ans += i1 - i0;
        }
        return ans;
    }
};  
// @lc code=end

