// Very trickly implementation. Use one vector and 3 indexs to store 3 queues. 
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 0)
            return -1;
        if (index < 7)
            return index;

        vector<int> res;
        res.push_back(1);
        int p2 = 0, p3 = 0,p5 = 0;
        while(res.size()<index) {
            int next = min(min(res[p2]*2, res[p3]*3), res[p5]*5);
            res.push_back(next);
            if (res[p2]*2==next) p2++;
            if (res[p3]*3==next) p3++;
            if (res[p5]*5==next) p5++;
        }
        return res[index-1];
    }
};
