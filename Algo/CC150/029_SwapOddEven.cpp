// Mask odd by 0101=0x5 and 1010=0xA.
class Exchange {
public:
    int exchangeOddEven(int x) {
        int odd = (x & 0x55555555);
        int even = (x & 0xAAAAAAAA);
        return (odd<<1) | (even>>1);
    }
};
