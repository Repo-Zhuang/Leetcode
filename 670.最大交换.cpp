// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem670.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int size = charArray.size();
        int max;
        for (int i =0; i < size; i++)
        {
            max = i;
            for (int j = i ; j < size; j++)
            {
                if (charArray[j] >= charArray[max])
                {
                    max = j;
                }
            }
            if (max != i && charArray[i] != charArray[max])
            {
                swap(charArray[i], charArray[max]);
                break;
            }
        }
        
        return stoi(charArray);
    }
    
};
// @lc code=end

