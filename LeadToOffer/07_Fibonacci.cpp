// DP. O(n) time. O(1) space.
class Solution {
public:
    int Fibonacci(int n) {
        if (n==0)
            return 0;
        if (n==1 || n==2)
            return 1;
        long long f1 = 1;
        long long f2 = 1;
        long long f = 0;
        for(int i=2; i<n; i++) {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
};
