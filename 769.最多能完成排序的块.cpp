/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cmax= 0 , chunks=0;
        for (int i = 0; i < arr.size(); i++)
        {
            cmax = max(cmax, arr[i]);
            if(cmax == i) chunks++;
        }
        return chunks;
        
    }
};
// @lc code=end

