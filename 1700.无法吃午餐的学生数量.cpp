/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int numone = accumulate(students.begin(), students.end(), 0);;
        int numzero = students.size() - numone;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0 && numzero > 0) {
                numzero--;
            } else if (sandwiches[i] == 1 && numone > 0) {
                numone--;
            } else {
                break;
            } 
        }
        return numone + numzero;
    }
};
// @lc code=end

