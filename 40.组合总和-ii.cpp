/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<int> track;
    int sum = 0;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int start) {
        if (sum == target)
        {
            res.push_back(track);
            return;
        }
        if (sum > target) return;
        
        for (int i = start; i < candidates.size(); i++) {

            if (i > start && candidates[i] == candidates[i - 1]) continue;
            track.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, i+1);
            sum -= candidates[i];
            track.pop_back();

        }
    }
};
// @lc code=end

