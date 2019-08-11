class Middle {
public:
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;

    void push_queue(int val, int seq) {
        if (seq%2==0) {
            min_q.push(val);
            max_q.push(min_q.top());
            min_q.pop();
        } else {
            max_q.push(val);
            min_q.push(max_q.top());
            max_q.pop();
        }
    }
    int get_median() {
        return max_q.top();
    }
    vector<int> getMiddle(vector<int> A, int n) {
        vector<int> res;
        for(int i=0; i<n; i++) {
            push_queue(A[i],i);
            res.push_back(get_median());
        }
        return res;
    }
};
