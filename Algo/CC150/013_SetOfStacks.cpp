// Just be careful of the status
class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        vector<vector<int> > stacks;
        int seq = ope.size();
        if (seq==0 || size==0)
            return stacks;
        int count = 0;
        vector<int> stack;
        stacks.push_back(stack);
        for(int i=0; i<seq; i++) {
            if (ope[i][0]==1) { //push
                if (stacks[count].size()==size){
                    vector<int> new_stack;
                    new_stack.push_back(ope[i][1]);
                    stacks.push_back(new_stack);
                    count++;
                } else
                    stacks[count].push_back(ope[i][1]);
            } else {
                if (stacks[count].size()==1) {
                    stacks.pop_back();
                    count --;
                }
                else
                    stacks[count].pop_back();
            }
        }
        return stacks;
    }
};
