/*
 * 最小栈
 * 链接：https://leetcode-cn.com/problems/min-stack/
 */

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> numStack;
    stack<int> minStack;
    MinStack() {

    }
    
    void push(int val) {
        numStack.push(val);
        if(minStack.empty())
        {
            minStack.push(val);
            return;
        }
        if(val >= minStack.top())
        {
            minStack.push(minStack.top());
        }
        else
        {
            minStack.push(val);
        }
    }
    
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    int top() {
        return numStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
