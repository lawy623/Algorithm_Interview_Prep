class KthNumber {
public:
    int findKth(int k) {
        vector<int> res;
        res.push_back(1);
        int m = 1;
        int p3=0, p5=0, p7=0;
        while(res.size()<k+1){
            m = min(min(res[p3]*3, res[p5]*5), res[p7]*7);
            if(m == res[p3]*3) p3++;
            if(m == res[p5]*5) p5++;
            if(m == res[p7]*7) p7++;
            res.push_back(m);
        }
        return m;
    }
};
