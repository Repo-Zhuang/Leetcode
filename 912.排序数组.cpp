/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int* temp = (int*)malloc(sizeof(int) * n); //需要一个临时的数组，去做归并的过程
        merge_sort(nums, 0, n - 1,temp);
        return nums;
    }
    void merge_sort(vector<int>& nums, int low, int high,int* temp) {
        if (low >= high) return;
        int mid = low +((high - low) >> 1);
        merge_sort(nums, low, mid, temp);
        merge_sort(nums, mid + 1, high, temp);
        merge(nums, low, mid, high, temp);    
    }
    void merge(vector<int>& nums, int low, int mid, int high, int* temp) {
        for (int i = low; i <= high; i++) {
            temp[i] = nums[i];
        }
        int i = low, j = mid + 1;
        for (int p = low; p <= high; p++) {
            if (i == mid + 1) {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            } else if (j == high + 1) {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
            }
        }
       
    }
};
// @lc code=end

