/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {

vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        vector<int> track;
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        backtrack(nums, track, k, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, int k, int start) {
        if (track.size() == k) {
            res.push_back(track);
            return ;
        }

        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, track, k, i + 1);
            track.pop_back();
        }
    }
};
// @lc code=end

