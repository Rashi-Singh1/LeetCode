class MinStack {
private:
    stack<int> s, minn;    
public:
    MinStack() {
        while(!s.empty()) s.pop();        
        while(!minn.empty()) minn.pop();
    }
    
    void push(int x) {
        s.push(x);
        if(minn.empty() || minn.top() >= x) minn.push(x);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if(top == minn.top()) minn.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */