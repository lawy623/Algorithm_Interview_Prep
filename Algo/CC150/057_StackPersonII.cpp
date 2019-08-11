class Stack {
public:
    int getHeight(vector<vector<int> > actors, int n) {
        for(int i=1;i<n;i++){
            for(int j=i-1; j>=0; j--) {
                if (actors[j][0]>actors[j+1][0])
                    swap(actors[j], actors[j+1]);
            }
        }
        int *dp = new int[n];
        dp[0] = 1;
        for(int i=1; i<n; i++) {
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if (actors[i][1]>actors[j][1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int max_v = 0;
        for(int i=0;i<n;i++){
            if (dp[i]>max_v)
                max_v = dp[i];
        }
        return max_v;
    }
};
