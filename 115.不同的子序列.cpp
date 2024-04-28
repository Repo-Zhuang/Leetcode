/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
private:
    const int MOD =1000000007;
public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) return 0;
        vector<int> dp(s.size()- t.size() + 1,0);

        for (int t.size() - 1= t.size() - 1; i < s.size(); i++) {
            if (s[i] != t[t.size() - 1]) continue;


        }
    }
};
// @lc code=end

