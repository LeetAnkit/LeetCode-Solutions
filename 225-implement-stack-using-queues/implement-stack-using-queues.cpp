class MyStack {
public:

  queue<int> qu;
    MyStack() {
        
    }
    
    void push(int x) {
        qu.push(x);
        int n = qu.size();

        for(int i =0; i< n-1 ; i++){
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int result = qu.front();
        qu.pop();
        return result;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
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