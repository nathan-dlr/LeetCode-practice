class MinStack {
public:
    int min;
    std::stack<std::pair<int, int>> minStack; 
    MinStack() {
        min = std::numeric_limits<int>::max();
    }
    
    void push(int value) {
        min = std::min(value, min);
        minStack.push({value, min});
    }
    
    void pop() {
        minStack.pop();
        if (!minStack.empty()) {
            min = minStack.top().second;
        }
        else {
            min = std::numeric_limits<int>::max();
        }
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */