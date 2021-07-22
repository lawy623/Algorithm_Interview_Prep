class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        if(pushed.size()!=popped.size())
            return false;
        if(pushed.size() == 0)
            return true;

        int i=0; int j=0;
        while(i < pushed.size()){
            s.push(pushed[i++]);
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};