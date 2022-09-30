/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:

    stack<int> In;
    stack<int> Out;

    MyQueue() {
       
    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        if (Out.empty()) {
            while (!In.empty()) {
                Out.push(In.top());
                In.pop();
            }
        }
        int res = Out.top();
        Out.pop();
        return res;
    }
    
    int peek() {
        if (Out.empty()) {
            while (!In.empty()) {
                Out.push(In.top());
                In.pop();
            }
        }
        return Out.top();
    }
    
    bool empty() {
        return In.empty() && Out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

