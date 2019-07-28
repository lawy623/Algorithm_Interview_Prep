// 1.
class Solution {
public:
    int Sum_Solution(int n) {
        int res = n;
        // when n == 0, return 0 directly.
        n && (res += Sum_Solution(n-1));
        return res;
    }
};
