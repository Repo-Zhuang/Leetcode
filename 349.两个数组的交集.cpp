/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> setnums1(nums1.begin(), nums1.end());

        for (int k: nums2)
        {
            if (setnums1.find(k) != setnums1.end())
            {
                result.insert(k);
            }
        }
        return vector<int>(result.begin(), result.end());
    }   
    
};
// @lc code=end

