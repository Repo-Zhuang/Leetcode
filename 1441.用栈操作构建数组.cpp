/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int k = 0;
        for (int i = 0; k < target.size(); i++) {
            if (i + 1 == target[k]) {
                result.push_back("Push");
                k++;
            }
            else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};
// @lc code=end

