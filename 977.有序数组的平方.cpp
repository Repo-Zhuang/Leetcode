/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> A(n, 0);
        int i = 0;
        int j = n - 1;
        int k = n - 1;
        while (i <= j) {
            if (pow(nums[i], 2) >= pow(nums[j], 2)) {
                A[k--] = pow(nums[i], 2);
                i++;
            }
            else {
                A[k--] = pow(nums[j], 2);
                j--;
            }
        }
        return A;
    }
};
// @lc code=end

