/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        int A[26] = {0};
        int result = 1;
        int Cursum = 0;
        A[s[0] - 'a']++;
        for (int i = 1; i < s.size(); i++) {
            
            Cursum = result + 1;
            result = result + Cursum - A[s[i] - 'a'];
            A[s[0] - 'a'] += result;
        }
        return result;
    }
};  
// @lc code=end

