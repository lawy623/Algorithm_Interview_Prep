// 1. Insertion Sort. O(n^2) time, O(n) space.
class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        stack<int> init;
        stack<int> temp;
        for(int i=numbers.size()-1; i>=0; i--) {
            init.push(numbers[i]);
        }
        while(!init.empty()){
            int v = init.top();
            init.pop();
            int count = 0;
            while(!temp.empty() && temp.top()>v) {
                init.push(temp.top());
                temp.pop();
                count++;
            }
            temp.push(v);
            while(count>0) {
                temp.push(init.top());
                init.pop();
                count--;
            }
        }
       vector<int> res;
       while(!temp.empty()){
           res.push_back(temp.top());
           temp.pop();
       }
        return res;
    }
};
