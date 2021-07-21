class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;

        if(isZero(x)) return 0.0;

        long n1 = n;
        if (n1<0){
            n1 *= -1;
            x = 1/x;
        }

        double res = 1.0;
        while(n1>0){
            if (n1 & 1) res *= x;
            x *= x;
            n1>>=1;
        }
        return res;
    }

    bool isZero(double x){
        return abs(x) <= 1e-15;
    }
};