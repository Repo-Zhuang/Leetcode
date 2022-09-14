/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st; //单调递增栈-此题存储的是下标 
    /*设置虚拟结尾的高度为0*/ 
    /*这样最后可以依次 计算 以弹出栈顶元素为高度的最大面积*/  
        heights.push_back(0);  
        int size = heights.size(), ans = 0;
        
        for(int i=0; i<size; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int pos = st.top();
                st.pop();
                ans = max(ans, heights[pos] * (st.empty()? i : i - st.top() - 1));
            }
            st.push(i);
        }
        
        return ans;
    }
};
// @lc code=end
/*观察上面各个阶段的栈内元素，栈顶元素的底下的这一个元素，就是栈顶元素左边第一个
大于该栈顶元素的元素，也就是说，当前栈顶元素弹出后，新的栈顶元素是弹出元素左边第一个
大于弹出元素的元素。另外，对于当前要入栈的元素 e，如果要先弹出栈顶元素才能入栈，说明
元素 e 是栈顶元素右边第一个大于该栈顶元素的元素。

总结起来：

我们每次用栈顶元素参与计算，

利用单调递增栈，我们能找到栈顶元素左右两边第一个大于该栈顶元素的元素；
利用单调递减栈，我们能找到栈顶元素左右两边第一个小于该栈顶元素的元素。
*/
