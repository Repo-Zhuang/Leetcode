/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
            sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b) -> bool {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            });

            vector<int> height(envelopes.size());
            for (int i = 0; i < height.size(); i++) {
                height[i] = envelopes[i][1];
            }

            return dp(height);
    }

    int dp(vector<int>& height) {
        vector<int> dp(height.size(), 1);

        for (int i = 0; i < height.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (height[i] > height[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 0;

        for (int i = 0; i < height.size(); i++) {
            res = max(dp[i], res);
        }
        return res;
    }
};
// @lc code=end

