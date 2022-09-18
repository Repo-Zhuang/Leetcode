/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1)
        {
            int Newn= 0;
            while (n)
            {
                Newn += pow(n % 10, 2);
                n = n / 10;
            }
            if (set.find(Newn) != set.end()) return false;
            set.insert(Newn);
            n = Newn;
        }
        return true;
    }
};
// @lc code=end

