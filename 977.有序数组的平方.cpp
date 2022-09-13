// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem977.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int>array(nums.size(), 0);
        int k = nums.size() - 1;
        for (int i = 0, j = n; i <= j;)
        {
            if (nums[i] * nums[i] <= nums[j] * nums[j])
            {
                array[k--] = nums[j] * nums[j];
                j--;
            }
            else 
            {
                array[k--] = nums[i] * nums[i];
                i++;
            }
        }
        return array;
        
    }
};
// @lc code=end

