class MaxQueue {
public:
    MaxQueue() {
    }

    int max_value() {
        if(!dq.empty()) return dq.front();
        else return -1;
    }

    void push_back(int value) {
        q.push(value);
        while(!dq.empty() && value > dq.back())
            dq.pop_back();
        dq.push_back(value);
    }

    int pop_front() {
        if(q.empty()) return -1;
        int v = q.front();
        q.pop();
        if(v == dq.front())
            dq.pop_front();
        return v;
    }

    queue<int> q;
    deque<int> dq;
};