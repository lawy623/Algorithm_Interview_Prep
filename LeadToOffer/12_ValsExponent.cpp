//1. normal calculation. Remember the corner cases.
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent==0)
            return 1.0;
        if ( isZero(base) ) {
            if (exponent==0) return 1;
            else return 0;
        }
        if (exponent<0) {
            exponent = -exponent;
            base = 1.0 / base;
        }
        double res = 1.0;
        for (int i=0; i<exponent; i++) {
            res *= base;
        }
        return res;
    }

    bool isZero(double val) {
        return abs(val) <= 1e-15;
    }
};

//2. O(logn) method using divide and conquer.
class Solution {
public:
    double PowerUnsignExp(double base, unsigned int exponent) {
        if (exponent == 0)
            return 0;
        if (exponent == 1)
            return base;

        double res = PowerUnsignExp(base, exponent >> 1);
        res *= res;
        if (exponent & 1)
            res *= base;
        return res;
    }
    double Power(double base, int exponent) {
        if (exponent==0)
            return 1.0;
        if ( isZero(base) ) {
            if (exponent==0) return 1;
            else return 0;
        }
        unsigned int exp = 0;
        if (exponent<0) {
            exp = (unsigned int) (-exponent);
            base = 1.0 / base;
        } else {
            exp = (unsigned int) exponent;
        }
        double res = 1.0;
        res = PowerUnsignExp(base, exp);
        return res;
    }

    bool isZero(double val) {
        return abs(val) <= 1e-15;
    }
};\
