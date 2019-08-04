class GoUpstairs {
public:
    int countWays(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;
        int f1=1, f2=2, f3=4;
        int f=0;
        for(int i=4; i<=n; i++){
            f = ((f1+f2)%1000000007 + f3)%1000000007; //be careful of mod here.
            f1 = f2;
            f2 = f3;
            f3 = f;
        }
        return f;
    }
};
