/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        //
        for (int num1: nums1){
            for (int num2: nums2){
                map[num1 + num2]++;
            }
        }

        int count = 0;
        for (int num3: nums3){
            for (int num4: nums4){
                if (map.find(-(num3 + num4)) != map.end()) 
                    count += map[-(num3 + num4)];
            }
        } 
        return count;
    }
};
// @lc code=end


