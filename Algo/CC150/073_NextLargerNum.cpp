// 1. Use a stack. The idea is that you dont need to save the values smaller than A[i] after it,
// since they can never be the next larger.
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        stack<int> large;
        vector<int> res;
        large.push(-1);
        for(int i=n-1; i>=0; i--) {
            while (large.size()>1 && large.top()<=A[i])
                large.pop();
            res.insert(res.begin(),large.top());
            large.push(A[i]);
        }
        return res;
    }
};
