/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue
{
public:
    stack<int> s;
    MyQueue() {}

    void push(int x)
    {
        pushHelper(x);
    }

    void pushHelper(int x)
    {
        if (s.empty())
        { // Base Condition
            s.push(x);
            return;
        }
        int temp = s.top();
        s.pop();
        pushHelper(x); // Recursion Call
        s.push(temp);
    }

    int pop()
    {
        int temp = s.top();
        s.pop();
        return temp;
    }

    int peek()
    {
        return s.top();
    }

    bool empty()
    {
        return s.empty();
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
