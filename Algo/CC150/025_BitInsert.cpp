class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        for(int k=j; k<=i; k++) {
            n |= (m & 1<<(k-j)) << j;
        }
        return n;
    }
};
