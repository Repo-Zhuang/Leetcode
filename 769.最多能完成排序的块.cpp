/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        int sum = 0;
        int Cursum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += i;
            Cursum += arr[i];
            if (Cursum == sum){
                sum = 0;
                Cursum = 0;
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

