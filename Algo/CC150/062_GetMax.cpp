class Max {
public:
    int getMax(int a, int b) {
        b = a-b;
        a -= b&(b>>31);
        return a;
    }
};
