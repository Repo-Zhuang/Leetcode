/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        //滑动窗口
        int n = code.size();
        vector<int> A(n, 0);
        if(k == 0) return A;
        int sum = 0;
        for(int i = 0; i < abs(k); i++) 
            sum += code[i]; 
        
        for(int i = 0; i < n; i++) {
            if(k > 0) {
                A[(i - 1 + n) % n] = sum;
            } else {
                A[(i - k + n) % n] = sum;
            }
            sum -= code[i];
            sum += code[(i + abs(k)) % n];
        }
        return A;
    }
};
// @lc code=end

