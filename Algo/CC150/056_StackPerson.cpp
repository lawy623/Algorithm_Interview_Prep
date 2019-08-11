class Stack {
public:
    int getHeight(vector<int> men, int n) {
        int *dp = new int[n];
        dp[0] = 1;
        for(int i=1; i<n; i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if (men[i]>men[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int max_h = 0;
        for(int i=0; i<n; i++){
            if (dp[i]>max_h)
                max_h = dp[i];
        }
        return max_h;
    }
};
