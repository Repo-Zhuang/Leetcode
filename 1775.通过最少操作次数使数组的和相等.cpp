/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        if (6 * nums1.size() < nums2.size() || 6 * nums2.size() < nums1.size())
            return -1; // 优化
        int d = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);
        if (d < 0) {
            d = -d;
            swap(nums1, nums2); // 统一让 nums1 的数变大，nums2 的数变小
        }
        int cnt[6]{}; // 统计每个数的最大变化量
        for (int x: nums1) ++cnt[6 - x]; // nums1 的变成 6
        for (int x: nums2) ++cnt[x - 1]; // nums2 的变成 1
        for (int i = 5, ans = 0;; --i) { // 从大到小枚举最大变化量 5 4 3 2 1
            if (i * cnt[i] >= d) // 可以让 d 变为 0
                return ans + (d + i - 1)/ i; // 向上取整
            ans += cnt[i]; // 需要所有最大变化量为 i 的数
            d -= i * cnt[i];
        }
    }
};
// @lc code=end

