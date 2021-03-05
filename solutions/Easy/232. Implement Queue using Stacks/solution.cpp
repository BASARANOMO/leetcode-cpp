class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        while (!inStack.empty()) inStack.pop();
        while (!outStack.empty()) outStack.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);

    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int temp = outStack.top();
        outStack.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (inStack.empty() && outStack.empty()) return true;
        return false;
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