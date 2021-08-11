class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = peek();
        if(!s2.empty()) s2.pop();
        return v;
    }

    /** Get the front element. */
    int peek() {
        if(s2.empty()){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.empty()) return -1;
        int v = s2.top();
        return v;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (s1.empty() && s2.empty());
    }

    stack<int> s1;
    stack<int> s2;
};
