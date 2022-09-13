/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
//
    int removeElement(vector<int>& nums, int val) {
        int slowindex = 0;
        for (int quickindex = 0; quickindex < nums.size(); quickindex++)
        {
            if (nums[quickindex] != val)
            {
                nums[slowindex++] = nums[quickindex];
            }
        }
        return slowindex;
    }
};
// @lc code=end

