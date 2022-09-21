/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> A;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() ; i++) {
            if (nums[i] > 0) return A;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int r = nums.size() - 1;
            while (j < r) {
                if (nums[i] + nums[j] + nums[r] < 0) j++;
                else if (nums[i] + nums[j] + nums[r] > 0) r--;
                else {
                    A.push_back(vector<int>{nums[i], nums[j], nums[r]});
                    while (r > j && nums[j] == nums[j + 1]) j++;
                    while (r > j && nums[r] == nums[r - 1]) r--;
                    r--;
                    j++;
                }
            }
        }
        return A;
    }

       
};
// @lc code=end

