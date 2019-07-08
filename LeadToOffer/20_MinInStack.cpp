// min array always keep the min up to now.
class Solution {
public:
    void push(int value) {
        vals.push(value);
        if (mins.empty() || mins.top()>value)
            mins.push(value);
        else
            mins.push(mins.top());
    }
    void pop() {
        vals.pop();
        mins.pop();
    }
    int top() {
        return vals.top();
    }
    int min() {
        return mins.top();
    }
private:
    stack<int> vals;
    stack<int> mins;
};
