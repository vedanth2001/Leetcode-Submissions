class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1;
    queue<int> q2;
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int y = q1.front();
            q1.pop();
            q2.push(y);
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */