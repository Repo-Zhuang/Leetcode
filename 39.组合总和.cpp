/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    int sum = 0;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int start) {
        if(sum == target) {
            res.push_back(track);
            return;
        }

        if(sum > target) return;

        for (int i =  start; i < candidates.size(); i++) {
            track.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, i);
            track.pop_back();
            sum -= candidates[i];
        }

    }
};
// @lc code=end

