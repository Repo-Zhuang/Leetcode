/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n);
        stack<int> index;
        for (int i = 0; i < n; i++)
        {             
            while (!index.empty() && temperatures[index.top()] < temperatures[i])
            {
                int pos = index.top();
                answer[pos] = i - pos;
                index.pop();
            }
            index.push(i);
        }
        return answer;
    }
};
// @lc code=end

