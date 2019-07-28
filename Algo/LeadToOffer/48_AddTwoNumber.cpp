//1. Add two number without +.
// Figure out bit manipulation is not hard, but the loop for carry is trickly.
class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum = 0;
        int carry = 0;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while(num2!=0);
        return sum;
    }
};
