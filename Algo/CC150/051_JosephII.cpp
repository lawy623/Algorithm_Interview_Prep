// Use list to simulate.
class Joseph {
public:
    int getResult(int n) {
        list<int> queue;
        for(int i=1; i<=n;i++)
            queue.push_back(i);
        list<int>::iterator iter = queue.begin();
        int max_break = 2;
        while(queue.size()>1){
            iter = queue.begin();
            int step = 1;
            while(iter!=queue.end()){
                if (step!=1)
                    iter = queue.erase(iter);
                else
                    iter++;
                step = (step%max_break) + 1;
            }
            max_break++;
            queue.push_front(queue.back());
            queue.pop_back();
        }
        return queue.front();
    }
};
