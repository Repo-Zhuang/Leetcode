/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        string s = "";
        int numsone = 0;
        int pos = arr.size();
        //将数组转换成字符串
        for (auto a : arr) {
            if (a == 1) numsone++;
            s += a + 0x30;
        }
        //如果1的数量不能被3整除，必然不能三等分
        if (numsone % 3 != 0) return {-1, -1};
        if (numsone == 0) return {0, pos - 1};
        //找到最后一部分起始1的位置
        int lastone = 0;
        while (lastone != numsone / 3) {
            pos--;
            if (arr[pos] == 1) lastone++;
        }
        //将最后一部分以1开始的字符串设为要寻找的字串
        int strlen = arr.size() - pos;
        string str = s.substr(pos, strlen);
        //开始找第一部分
        if (s.find(str, 0) == string::npos) return {-1, -1};
        int i = s.find(str, 0) + strlen - 1;
        //开始找第二部分
        if (s.find(str, i + 1) == string::npos || s.find(str, i + 1) + strlen > pos) return {-1, -1};
        int j = s.find(str, i + 1) + strlen;
        return {i, j};

    }
};
// @lc code=end

