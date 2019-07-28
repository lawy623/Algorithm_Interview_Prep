//1. Remember to avoid bit overflow(only one case. Every time, we do not only deduct divisor, but multiple 2.
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend == INT_MIN && divisor == -1) return INT_MAX;
            long long a = dividend >= 0 ? dividend : -(long long)dividend;
            long long b = divisor >= 0 ? divisor : -(long long)divisor;
            long long result = 0;

            while (a >= b) {
                long long c = b;
                for (int i = 0; a >= c; ++i, c <<= 1) { //Move c to left by 1 bit(Multiple 2)
                    a -= c;
                    result += 1 << i;
                }
            }

            return ((dividend^divisor) >> 31) ? (-result) : (result);  //This technique is good to dicide the sign.
        }
};