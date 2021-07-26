// Use two queue. O(n) space, O(logn) time
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count = 0;
    }

    void addNum(int num) {
        if(count % 2 == 0){
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        } else {
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        }
        count++;
    }

    double findMedian() {
        if(count % 2 == 1)
            return max_q.top();
        else
            return (double)(max_q.top() + min_q.top()) / 2.0;
    }

    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;
    int count;
};

// more clear. But it contains repetitive operation
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        max_q.push(num);
        min_q.push(max_q.top());
        max_q.pop();
        if(max_q.size() != min_q.size()){
            max_q.push(min_q.top());
            min_q.pop();
        }
    }

    double findMedian() {
        return max_q.size() > min_q.size()? max_q.top():(double)(max_q.top() + min_q.top()) / 2.0;
    }

    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;
};