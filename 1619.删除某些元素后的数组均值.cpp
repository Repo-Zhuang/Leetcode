/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        
        int len = arr.size();
        int k = len / 20;
        sort(arr.begin(), arr.end());
        double result = 0;
        for (int i = k ; i < len - k; i++)
        {
            result += arr[i];
        }
   
        return result / (len - 2*k);
       
       /*  int n = arr.size();
        sort(arr.begin(), arr.end());
        double partialSum = accumulate(arr.begin() + n / 20, arr.end() -n / 20, 0);
        return partialSum / (n * 0.9); */
    }

};
// @lc code=end

