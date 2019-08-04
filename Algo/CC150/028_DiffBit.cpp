class Transform {
public:
    int calcCost(int A, int B) {
        int D = A ^ B;
        int count=0;
        for(int i=0;i<32;i++){
            count += (D>>i & 1);
        }
        return count;
    }
};
