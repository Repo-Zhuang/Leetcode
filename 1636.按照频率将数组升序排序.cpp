/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

// @lc code=start
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if (map[a] != map[b]) return map[a] < map[b];
            return a > b;
        } );
        
        return nums;
    }
};
// @lc code=end

