// circle starts from 1. But the transfer function is 0-based.
class Joseph {
public:
    int getResult(int n, int m) {
        int dp = 0;
        for(int i=2; i<=n; i++) {
            dp = (dp+m)%i;
        }
        return dp+1;
    }
};
