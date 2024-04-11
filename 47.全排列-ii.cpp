/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums, used);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (track.size() == nums.size()){
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            if( i > 0 && nums[i] == nums[i - 1] && used[i-1] == true) continue;
            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = false;
            track.pop_back();
        }
    }
};
// @lc code=end

