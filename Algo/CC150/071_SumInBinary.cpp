class UnusualAdd {
public:
    int addAB(int A, int B) {
        int sum = 0;
        int carry = 0;
        do {
            sum = A ^ B;
            carry = (A&B)<<1;
            A=sum;
            B=carry;
        } while(B!=0);
        return sum;
    }
};
