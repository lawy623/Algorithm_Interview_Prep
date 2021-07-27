class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1; long long start = 1; long long count = 9;
        while(n > count){
            n -= count;
            start *= 10;
            digit += 1;
            count = start * digit * 9;
        }
        int num = start + (n - 1) / digit;
        return to_string(num)[(n-1)%digit] - '0';
    }
};