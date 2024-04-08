/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
vector<vector<int>>  res;
vector<int> track;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<bool> used(nums.size(),false);
        backtrack(nums, used);

        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used) {

        
        if (track.size() == nums.size()) {
            // 收集叶子节点上的值
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,used);
            used[i] = false;
            track.pop_back();
        }

    }
};
// @lc code=end

