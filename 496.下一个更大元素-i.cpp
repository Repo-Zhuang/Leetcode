/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int,int> temp;
        stack<int> index;
        for (int i = 0; i < m; i++)
        {
            while (!index.empty() && nums2[index.top()] < nums2[i])
            {
                int pos = index.top();
                index.pop();
                temp[nums2[pos]] = nums2[i];
            }
            index.push(i);
        }
        while (!index.empty())
        {
            temp[nums2[index.top()]] = -1;
            index.pop();
        }
        
        for (int i = 0; i < n; i++)
        {
            nums1[i] = temp[nums1[i]];
        }
    return nums1;    
    }
};
// @lc code=end

