class CustomStack {
public:
     deque<int>dq;
     int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(dq.size() == size) return;
        dq.push_back(x);
    }
    
    int pop() {
        if(!dq.size()) return -1;
        int back = dq.back();
        dq.pop_back();
        return back;
    }
    
    void increment(int k, int val) {
        vector<int>temp;
        int op = min(k, (int)dq.size());

        while(op--){
            temp.push_back(dq.front() + val);
            dq.pop_front();
        }
        for(int i = temp.size() - 1;i >= 0;i--) dq.push_front(temp[i]);
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