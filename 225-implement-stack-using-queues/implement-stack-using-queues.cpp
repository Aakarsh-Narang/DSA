class MyStack {
public:
    queue<int> main, temp;
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(main.empty()) return -1;
        while(main.size() > 1){
            temp.push(main.front());
            main.pop();
        }

        int ans = main.front();
        main.pop();

        while(!temp.empty()){
            main.push(temp.front());
            temp.pop();
        }

        return ans;
    }
    
    int top() {
        if(main.empty()) return -1;
         while(main.size() > 1){
            temp.push(main.front());
            main.pop();
        }

        int ans = main.front();
        temp.push(main.front());
        main.pop();

        while(!temp.empty()){
            main.push(temp.front());
            temp.pop();
        }

        return ans;
    }
    
    bool empty() {
        return main.empty();
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