// 1. Use stacks
class LCA {
public:
    int getLCA(int a, int b) {
        stack<int> s1;
        stack<int> s2;
        while(a) {
            s1.push(a);
            a /= 2;
        }
        while(b) {
            s2.push(b);
            b /= 2;
        }
        int last = 1;
        while(s1.top()==s2.top()){
            last = s1.top();
            s1.pop();
            s2.pop();
        }
        return last;
    }
};

// 2. Half the large one until they are the same.
class LCA {
public:
    int getLCA(int a, int b) {
        while(a!=b){
            if (a>b)
                a /= 2;
            else
                b /= 2;
        }
        return a;
    }
};
