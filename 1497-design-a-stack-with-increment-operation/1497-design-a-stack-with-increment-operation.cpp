class CustomStack {
public:
     vector<int>arr;
     int top = -1, size;
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        size = maxSize;
    }
    
    void push(int x) {
        if(top == size - 1) return;
        arr[++top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int val = arr[top];
        top--;
        return val;
    }
    
    void increment(int k, int val) {
        for(int i = 0;i <= min(k - 1, top);i++)
        arr[i] += val;
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */