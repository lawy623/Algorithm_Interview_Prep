// binary search
class Solution {
public:
    int mySqrt(int x) {
        long l = 1; long r = x;  // in case overflow
        while(l<=r){
            long long m = (l+r)/2;
            long long y = m *m;
            if(y == x) return m;
            else if(y>x) r = m-1;
            else l = m+1;
        }
        return r;
    }
};

// NewTon
class Solution {
public:
    int mySqrt(int x) {
        double x0 = (double)x;
        double y = 0.5 * ((double)x + 1.0);
        while(abs(y-x0)>1e-7){
            x0 = y;
            y = 0.5 * (y + (double)x/y);
        }
        return (int)y;
    }
};