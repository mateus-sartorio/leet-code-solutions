#include <stack>

class MinStack {
private:
    std::stack<int> minimum_stack;
    std::stack<int> stack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        
        if(minimum_stack.empty()) {
            minimum_stack.push(val);
        }
        else if(val <= minimum_stack.top()) {
            minimum_stack.push(val);
        }
    }
    
    void pop() {
        int top = stack.top();

        stack.pop();

        if(top == minimum_stack.top()) {
            minimum_stack.pop();
        }
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minimum_stack.top();
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
