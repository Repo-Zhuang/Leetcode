#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>
#include <string>

using namespace std;
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
        	while(!st.empty() && heights[st.top()] >= heights[i]) {
        		int pos = st.top();
        		st.pop();
        		ans = max(ans, heights[pos] * (st.empty()? i: i - st.top() - 1) );
                cout << ans << endl;
        	}
        	st.push(i);
        }
        
        return ans;
    }
};

int main()
{
    vector<int> nums = {1,2,3};
    Solution m;

    cout << m.largestRectangleArea(nums);

   
}