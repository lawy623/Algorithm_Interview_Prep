//1. Use a circle linked list.
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n<=0 || m<=0)
            return -1;
        if (m==1)
            return n-1;

        list<int> circle;
        for(int i=0; i<n; i++)
            circle.push_back(i);
        list<int>::iterator iter = circle.begin();
        while(circle.size()>1) {
            for(int i=0; i<m-1; i++) {
                if (iter==circle.end())
                    iter = circle.begin();
                iter++;
            }
            if (iter==circle.end())
                iter = circle.begin();
            iter = circle.erase(iter);
        }
        return circle.front();
    }
};
