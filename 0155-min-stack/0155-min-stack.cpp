class MinStack {
public:
    int tos = -1, mini = INT_MAX;
    stack<pair<int,int>>stk;
    MinStack() {
        tos = -1;
    }
    
    void push(int val) {
        mini = min(mini, val);
        stk.push({val, mini});
        tos++;
        return;
    }
    
    void pop() {
        stk.pop();
         tos--;
         if(tos != -1)
         mini = stk.top().second;
         else{
         mini = INT_MAX;
         }
    }
    
    int top() {
        // if(tos == -1) return -1;
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;        
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