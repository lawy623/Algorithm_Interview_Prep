class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int n = q.size();
        q.push(x);
        while(n>0){
            int v = q.front();
            q.push(v);
            q.pop();
            n--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = top();
        if(!empty()) q.pop();
        return v;
    }

    /** Get the top element. */
    int top() {
        if(empty()) return -1;
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
    queue<int> q;
};